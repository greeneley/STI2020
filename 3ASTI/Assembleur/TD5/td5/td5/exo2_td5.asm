.386
.model flat
.data
string1 byte "AZERTYU"
;;;;;;;;;;;;
.code
main proc
	mov edi, offset string1
	mov ecx, lengthof string1
	lea esi, string1
	mov al,'Z'
	cld
	repne scasb
	jnz quit
	dec edi
main endp
quit:
end
