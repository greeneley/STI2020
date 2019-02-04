.386
.model flat
.data

.code
main proc
	mov ax, 78
	mov ax,[ebx]
	add ax,7659h
	mov ds:[01000000h], ax
	mov cx, ds+20000000h
	add bx,[esi]
	mov [esi+ebp],bx
	sub al,1
	mov [esi+ebp+10h],al
main endp
end