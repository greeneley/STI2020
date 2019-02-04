.386
.model flat
.data
op1 BYTE 10
op2 BYTE 10
x BYTE ?
.code
; ---------Segment du code -------------
	main PROC
	mov al,op1
	cmp al,op2
	jne etiquette
	mov x,1
	jmp Quit
etiquette:
	mov x,2
	jmp Quit
Quit:
	main ENDP
	end