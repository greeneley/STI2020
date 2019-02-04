386
.model flat
.data
eax ?
.code
main proc
	l1:
		mov cl,[eax]
		cmp cl, ''
		jb l2
		cmp cl,','
		jnz l3
	l2:
		move byte ptr[eax]
	l3:
		mov cl,[eax+1]
		inc eax
		test cl,cl
		jnz l1
main endp
end

