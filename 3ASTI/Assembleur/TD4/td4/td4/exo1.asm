.386
.model flat,stdcall
.data
arr dw 5,1,3
j BYTE ?
tmp BYTE ?
en_desordre BYTE ? 
.code
; int j = 0
; int tmp =0
; int en_desordre=1
start:
	main proc
	mov j,0
	mov tmp,0
	mov en_desordre,1
while:
	;while(en_desordre)
	cmp en_desordre,0
	je end
	mov en_desordre,0 ; en_desordre = FALSE
forj:
;GET t[j] 
	mov si, offset arr
	mov ax, j
	shl ax , 1 ; 
	add si, ax
	mov ax, [si] ;  AX = t[j]
; GET t[j+1]
	int j ; j++
	mov di,offset arr
	mov cx,j 
	shl cx,1
	add di,cx
	mov cx,[di] ; CX=t[j+1]
	; if (t[j]>t[j+1])
	cmp ax,cx
	; if t[j] <= t[j+1] no exchange
	jbe smaller
	; exchanger 
	mov bx, tmp ; BX=tmp
	mov bx,cx; tmp = t[j+1]
	mov cx,ax; t[j+1]=t[j]
	mov ax,bx; t[j]=tmp;
	mov en_desordre,1
	jmp smaller
smaller:
	; NEXT j
	cmp j, 2 ; 2 is number of array (n-1)
	jbe forj ; if (j<= n-1) REPEAT
	jmp end
end:
	inc	21h
main endp
end;
