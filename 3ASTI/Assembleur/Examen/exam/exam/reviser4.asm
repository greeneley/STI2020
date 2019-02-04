.386
.model flat
.data
Rval word ?
Xval word 64h
Yval word 0Ah
Zval word 05h
var1 word 03h
var2 word 04h
var3 word 07h
var4 word ?
.code
main proc
	;;;;;;;;;;;;; operation a 
	mov ax, Yval ; ax=Yval
	mov bx, Zval; bx = Zval
	sub ax, bx ; ax= Yval -Zval
	mov bx,Xval; bx= Xval
	neg bx; bx= -Xval
	add ax,bx ; operation
	mov Rval,ax;
	;;;;;;;;;;;;;;;;;;; operation
	mov bx, var1; bx=var1
	add bx, var2; bx= var1+var2
	mov ax,var3; ax=var3
	mul bx ; operation
	mov var4,ax;
	;;;;;;;;;;;;;;;; operation c
	mov ax,var2; ax=var2
	div var3; 
	mov bx,dx ; bx=(var2%var3)
	mov ax,var1
	div bx ; var1/(var2%var3)
	mov bx,5
	mul bx ; var1*5/(var2%var3)
	mov var4,ax
	neg var4
	;;;;	
main endp
end