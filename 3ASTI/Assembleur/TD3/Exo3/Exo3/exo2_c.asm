.386
.model flat
.data 
var1 WORD 45
var2 WORD 1254
var3 WORD 111
.code
;------------if(bx<=cx)&&(cx>dx) {ax=5,dx=6}-----------------
start:
	main proc
	mov bx,var1 ; bx=var1 
	mov cx,var2 ; cx=var2
	mov dx,var3 ; dx=var3
	cmp bx,cx ; comparaison bx et cx
	ja QUIT
	cmp cx,dx
	jbe QUIT
	mov ax,5
	mov dx,6
	jmp QUIT
QUIT:
	main endp
	end