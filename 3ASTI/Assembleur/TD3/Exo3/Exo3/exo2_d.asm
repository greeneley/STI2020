.386
.model flat
.data
var1 WORD 1
var2 WORD 5
var3 WORD 5
x WORD ?
.code
;---------------Segment du code-----------------
start: 
	main proc
	mov ax,var1
	mov bx,var2
	mov cx,var3
boucle:
	cmp ax,bx
	jae fin
	push ax
	inc ax
	cmp bx,cx
	jne etique
	mov x,2
	jmp boucle
etique:
	mov x,3
	jmp boucle
fin: 
	main endp
	end
