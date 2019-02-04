.386
.model flat
.data
var1 BYTE 15
var2 BYTE 12
var3 BYTE ?
var4 BYTE ?
.code
start:
	main proc
	mov al,var1
	cmp al,var2
	ja etique   ;  neu var1 > var2 thi nhay den etique
	mov var3,10
	jmp QUIT
etique:
	mov var3,6
	mov var4,7
	jmp QUIT
QUIT:
	main endp
	end