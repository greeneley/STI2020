.386
.model flat
.data
Count = 100
string1 byte Count dup (?)
.code
main proc
 mov edi, offset string1
 mov al, 0FFh 
 mov ecx, Count
 call calcule
 jmp quit
main endp
;;;;;
calcule proc	
	cld 
	rep stosb
	mov bl,[string1+5]
	ret
calcule endp
;;;
quit:
end