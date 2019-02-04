.386
.model flat
.data
var1 word 1
var2 word 5
var3 word ?
x word ?
.code
start:
	main proc
	mov ax,var1
	mov bx,var2
	mov cx,var3
boucle:
	cmp ax,bx
	jae quit
	inc var1; val1++
	cmp bx,cx
	jne lb1
	mov x,2
	jmp boucle
lb1:
	mov x,3
	jmp boucle
quit:
	main endp
	end

