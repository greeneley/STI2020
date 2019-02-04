//heap = list of free blocks (@0: size, @1:next @2 -- @size+1: free memory)
void __init_heap()
{
  //set the first free block at @0, make it covering all the memory
  __asm {
    ldi r0,0
    ldi r1,0
    st r1,[r0]
      //free_block[0].size = 0

    ldi r0,1
    ldi r1,3
    st r1,[r0]
      //free_block[0].next = 3 

    ldi r0,2
    ldi r1,0
    st r1,[r0]
      //free_block[0].pred = 0 (null)

    ldi r0,3
    ldi r1,127
    st r1,[r0]
      //free_block[1].size = 127 bytes

    ldi r0,4
    ldi r1,0
    st r1,[r0]
      //free_block[1].next = 0 (null)

    ldi r0,5
    ldi r1,0
    st r1,[r0]
      //free_block[1].pred = 0
  }
}


int malloc(int size)
{
  __asm {
    ld r1,[r7+4] //r1 = size
    ldi r0,0
next_free_block:
    ld r2,[r0] //r2 = free_block[r0].size
    ble r1,r2,free_block_found
free_block_not_ok:
    ld r0,[r0+1] //r0 = free_block[r0].next
    ldi r3,0
    ble r0,r3,no_free_block //0 or >= 128 => out_of_memory
    j next_free_block
no_free_block:
    ldi r3,1 //status 1: no free block
    ldi r0,13
    st r0,[r0+63]
    ldi r0,'E'
    st r0,[r0+63]
    ldi r0,'1'
    st r0,[r0+63] //Display "Error 1" (E1)
malloc_error:
    j malloc_error
free_block_found:
    sub r2,r2,r1 //free_block[r0].size -= size
    ldi r3,0 //status 0: free block found 
    ble r2,r3,empty_free_block //0? remove the free block.
    add r4,r0,r1 //@new free_block = @free_block+size
    st r2,[r4]  //move free_block[r0].size (-= size)
    ld r5,[r0+1]
    st r5,[r4+1]  //move free_block[r0].next
    ld r5,[r0+2]
    st r5,[r4+2]  //move free_block[r0].pred
    j update_pred   
empty_free_block:
    ld r4,[r0+1] //@new freeblock <-- free_block[r0].next
update_pred:
    ld r5,[r0+2] 
    st r4,[r5+1] //update (free_block[0].pred).next (always exists)
no_pred:
end_asm_malloc:
    ldi r3,1
    sub r1,r1,r3 //size=size-1
    add r2,r0,r1 //r2 = r0+size-1
    sub r3,r2,r3 //r3 = r2-1
    st r3,[r2]   //first byte = pointer to the remaining area
  }
}


void free(int address, int size)
{
  __asm {
    ld r1,[r7+5] //r1 = address
    ld r2,[r7+4] //r2 = size
    sub r1,r1,r2 //
    ldi r0,1     //address = address-size+1
    add r1,r1,r0 //
    ldi r0,0
next_free_block1:
    ble r1,r0,next_free_block_found
    ldi r3,0
    add r4,r0,r3 //r4 = free_block[r0]
    ld r0,[r0+1] //r0 = free_block[r0].next
    ble r0,r3,no_more_free_block //0 or >= 128 => out_of_memory
    j next_free_block1
next_free_block_found:
    st r1,[r0+2] //free_block[r0].pred = address
no_more_free_block:
    st r1,[r4+1] //(free_block[r0].pred).next = address
set_new_free_block:
    st r2,[r1] //new free_block.size = r2
    st r0,[r1+1] //new free_block.next = r0
    st r4,[r1+2] //new free_block.pred = r4
  }
}

void print_char(char c)
{
  __asm {
    ld r0,[r7+4]
    st r0,[r0+63]
  }
}

void print_int(int i)
{
  __asm {
    ld r0,[r7+4]
    ldi r1,10
    ble r0,r1,one_digit
    ldi r2,'1'
    st r2,[r0+63]
    sub r0,r0,r1
  one_digit:
    ldi r1,'0'
    add r0,r1,r0
    st r0,[r0+63]
  }
}

void print_string(char* string)
{
  __asm {
      ld r0,[r7+4]
      ldi r1,1
      ldi r2,0
    print_string_loop:
      ld r3,[r0]
      st r3,[r0+63]
      ble r3,r2,print_string_end_loop
      sub r0,r0,r1
      j print_string_loop
    print_string_end_loop:
  }
}

void print_newline()
{
  __asm {
    ldi r0,13
    st r0,[r0+63]
  }
}

char input_char()
{
  __asm {
    ldi r0,0
  input_char_loop:
    ld r2,[r0+63]
    ble r2,r0,input_char_loop
    st r2,[r0+63]
  }
}
