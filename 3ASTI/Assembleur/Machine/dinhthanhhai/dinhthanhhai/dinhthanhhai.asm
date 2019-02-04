.386
.model flat
.data
list sdword 5,2,3,-10,15,0,-1,-9,13,21
.code
start:
	main proc
	mov edx, list[0]; edx= lagrest=list[0]
	mov ebx, 36
	mov ecx, lengthof list ; ecx= count
	call large 
	jmp quit 
	main endp
	 ;;;;;;;;;;;;;;;;;;;;;;;;;;;
	; fonction lagre(int list[], int size, int largest)
	large proc
		cmp ecx,1 ; if size==1
		je l1
		cmp ecx,0 
		jb l1 ; if size <0
		cmp list[ebx],edx 
		jle l2 ; if(list[size] <= largest)
		mov edx,list[ebx] ; largest= list[size]
		jmp l2 ; return
	l1: ; return largest
		ret
	l2:
		; return largest=large(list,size -1, largest)
		sub ebx,4
		dec ecx
		loop large
	large endp
quit:
end
