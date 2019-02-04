__init_heap:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_0:
  ldi r3, 0
  sub r6, r6, r3
      ldi r0,0	//inline asm
      ldi r1,0	//inline asm
      st r1,[r0]	//inline asm
        //free_block[0].size = 0	//inline asm
      ldi r0,1	//inline asm
      ldi r1,3	//inline asm
      st r1,[r0]	//inline asm
        //free_block[0].next = 3 	//inline asm
      ldi r0,2	//inline asm
      ldi r1,0	//inline asm
      st r1,[r0]	//inline asm
        //free_block[0].pred = 0 (null)	//inline asm
      ldi r0,3	//inline asm
      ldi r1,127	//inline asm
      st r1,[r0]	//inline asm
        //free_block[1].size = 127 bytes	//inline asm
      ldi r0,4	//inline asm
      ldi r1,0	//inline asm
      st r1,[r0]	//inline asm
        //free_block[1].next = 0 (null)	//inline asm
      ldi r0,5	//inline asm
      ldi r1,0	//inline asm
      st r1,[r0]	//inline asm
        //free_block[1].pred = 0	//inline asm
__init_heap_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 2
  add r6, r6, r0
  ld r0, [r6 - 1]
  ld r1, [r6 + 0]
  ja r0, r1
malloc:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_1:
  ldi r3, 0
  sub r6, r6, r3
  ld r3, [r7 + 4]
      ld r1,[r7+4] //r1 = size	//inline asm
      ldi r0,0	//inline asm
  next_free_block:	//inline asm
      ld r2,[r0] //r2 = free_block[r0].size	//inline asm
      ble r1,r2,free_block_found	//inline asm
  free_block_not_ok:	//inline asm
      ld r0,[r0+1] //r0 = free_block[r0].next	//inline asm
      ldi r3,0	//inline asm
      ble r0,r3,no_free_block //0 or >= 128 => out_of_memory	//inline asm
      j next_free_block	//inline asm
  no_free_block:	//inline asm
      ldi r3,1 //status 1: no free block	//inline asm
      ldi r0,13	//inline asm
      st r0,[r0+63]	//inline asm
      ldi r0,'E'	//inline asm
      st r0,[r0+63]	//inline asm
      ldi r0,'1'	//inline asm
      st r0,[r0+63] //Display "Error 1" (E1)	//inline asm
  malloc_error:	//inline asm
      j malloc_error	//inline asm
  free_block_found:	//inline asm
      sub r2,r2,r1 //free_block[r0].size -= size	//inline asm
      ldi r3,0 //status 0: free block found 	//inline asm
      ble r2,r3,empty_free_block //0? remove the free block.	//inline asm
      add r4,r0,r1 //@new free_block = @free_block+size	//inline asm
      st r2,[r4]  //move free_block[r0].size (-= size)	//inline asm
      ld r5,[r0+1]	//inline asm
      st r5,[r4+1]  //move free_block[r0].next	//inline asm
      ld r5,[r0+2]	//inline asm
      st r5,[r4+2]  //move free_block[r0].pred	//inline asm
      j update_pred   	//inline asm
  empty_free_block:	//inline asm
      ld r4,[r0+1] //@new freeblock <-- free_block[r0].next	//inline asm
  update_pred:	//inline asm
      ld r5,[r0+2] 	//inline asm
      st r4,[r5+1] //update (free_block[0].pred).next (always exists)	//inline asm
  no_pred:	//inline asm
  end_asm_malloc:	//inline asm
      ldi r3,1	//inline asm
      sub r1,r1,r3 //size=size-1	//inline asm
      add r2,r0,r1 //r2 = r0+size-1	//inline asm
      sub r3,r2,r3 //r3 = r2-1	//inline asm
      st r3,[r2]   //first byte = pointer to the remaining area	//inline asm
malloc_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 3
  add r6, r6, r0
  ld r0, [r6 - 2]
  ld r1, [r6 - 1]
  ja r0, r1
free:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_2:
  ldi r3, 0
  sub r6, r6, r3
  ld r3, [r7 + 5]
  ld r3, [r7 + 4]
      ld r1,[r7+5] //r1 = address	//inline asm
      ld r2,[r7+4] //r2 = size	//inline asm
      sub r1,r1,r2 //	//inline asm
      ldi r0,1     //address = address-size+1	//inline asm
      add r1,r1,r0 //	//inline asm
      ldi r0,0	//inline asm
  next_free_block1:	//inline asm
      ble r1,r0,next_free_block_found	//inline asm
      ldi r3,0	//inline asm
      add r4,r0,r3 //r4 = free_block[r0]	//inline asm
      ld r0,[r0+1] //r0 = free_block[r0].next	//inline asm
      ble r0,r3,no_more_free_block //0 or >= 128 => out_of_memory	//inline asm
      j next_free_block1	//inline asm
  next_free_block_found:	//inline asm
      st r1,[r0+2] //free_block[r0].pred = address	//inline asm
  no_more_free_block:	//inline asm
      st r1,[r4+1] //(free_block[r0].pred).next = address	//inline asm
  set_new_free_block:	//inline asm
      st r2,[r1] //new free_block.size = r2	//inline asm
      st r0,[r1+1] //new free_block.next = r0	//inline asm
      st r4,[r1+2] //new free_block.pred = r4	//inline asm
free_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 4
  add r6, r6, r0
  ld r0, [r6 - 3]
  ld r1, [r6 - 2]
  ja r0, r1
print_char:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_3:
  ldi r3, 0
  sub r6, r6, r3
  ld r3, [r7 + 4]
      ld r0,[r7+4]	//inline asm
      st r0,[r0+63]	//inline asm
print_char_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 3
  add r6, r6, r0
  ld r0, [r6 - 2]
  ld r1, [r6 - 1]
  ja r0, r1
print_int:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_4:
  ldi r3, 0
  sub r6, r6, r3
  ld r3, [r7 + 4]
      ld r0,[r7+4]	//inline asm
      ldi r1,10	//inline asm
      ble r0,r1,one_digit	//inline asm
      ldi r2,'1'	//inline asm
      st r2,[r0+63]	//inline asm
      sub r0,r0,r1	//inline asm
    one_digit:	//inline asm
      ldi r1,'0'	//inline asm
      add r0,r1,r0	//inline asm
      st r0,[r0+63]	//inline asm
print_int_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 3
  add r6, r6, r0
  ld r0, [r6 - 2]
  ld r1, [r6 - 1]
  ja r0, r1
print_string:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_5:
  ldi r3, 0
  sub r6, r6, r3
  ld r3, [r7 + 4]
        ld r0,[r7+4]	//inline asm
        ldi r1,1	//inline asm
        ldi r2,0	//inline asm
      print_string_loop:	//inline asm
        ld r3,[r0]	//inline asm
        st r3,[r0+63]	//inline asm
        ble r3,r2,print_string_end_loop	//inline asm
        sub r0,r0,r1	//inline asm
        j print_string_loop	//inline asm
      print_string_end_loop:	//inline asm
print_string_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 3
  add r6, r6, r0
  ld r0, [r6 - 2]
  ld r1, [r6 - 1]
  ja r0, r1
print_newline:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_6:
  ldi r3, 0
  sub r6, r6, r3
      ldi r0,13	//inline asm
      st r0,[r0+63]	//inline asm
print_newline_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 2
  add r6, r6, r0
  ld r0, [r6 - 1]
  ld r1, [r6 + 0]
  ja r0, r1
input_char:
  st r7, [r6 + 0]
  ldi r0, 1
  sub r6, r6, r0
  ldi r0, 0
  add r7, r6, r0
_alloc_7:
  ldi r3, 0
  sub r6, r6, r3
      ldi r0,0	//inline asm
    input_char_loop:	//inline asm
      ld r2,[r0+63]	//inline asm
      ble r2,r0,input_char_loop	//inline asm
      st r2,[r0+63]	//inline asm
input_char_end:
  ldi r0, 0
  add r6, r7, r0
  ldi r0, 1
  add r6, r6, r0
  ld r7, [r6 + 0]
  ldi r0, 2
  add r6, r6, r0
  ld r0, [r6 - 1]
  ld r1, [r6 + 0]
  ja r0, r1
