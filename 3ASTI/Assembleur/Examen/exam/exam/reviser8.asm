.386
.model flat
.data
tab dword 10 dup (?)
.code
main proc
start:
	mov eax, 5
	mov ebx,eax
	mov ecx,0
	lea esi,tab
	call facto
main endp
;;;;;;;;;;;;
facto proc
	dec ebx
	mov [esi],eax
	add esi,4
	inc ecx
	cmp ebx,1
	je fin
	mul ebx
	call facto
fin:
	ret
facto endp
end