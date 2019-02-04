.386
.model flat
.data
nb dword 10
.code
main proc
	mov ax, 78
	mov bx, 23
	mov ax,[ebx]
main endp
end