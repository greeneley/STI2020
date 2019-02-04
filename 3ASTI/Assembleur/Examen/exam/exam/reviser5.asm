.386
.model flat
.data
op1 word 1000h
op2 word 2000h
X word ?
.code
main proc
start:
	mov ax,op1
	mov bx,op2
	cmp ax,bx
	je lb1
	mov x,2
	jmp quit
lb1: 
	mov x,1
	jmp quit
main endp
quit:
end