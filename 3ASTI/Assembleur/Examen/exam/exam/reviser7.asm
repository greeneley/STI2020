.386
.model flat
.data
tab word 1h,5h,11h,2h,7h,3h
.code
start:
	main proc
	mov ax, lengthof tab; dx=numero d'element de tab
	dec ax ; dx--
	mov si,0 ; j=si=0
	mov bx,0 ; bx=tmp
	mov cx, 1; en_desordre=1 
boucle:
	;=============WHILE=============
	cmp cx,0
	je finboucle
	mov cx, 0 ; donne en_desordre = FALSE
	
L1:
	;=============FOR===============
	cmp si,ax
	jae finboucle
	mov dx,tab[si]
	cmp dx,tab[si+2]
	jbe lb1
	;;;;;;;;; exchange
	xchg dx,tab[si+2]
	mov tab[si],dx
	mov cx,1;
	jmp lb1
lb1:
	;;;;;;;;;;; FIN IF =========
	add si,2
	jmp L1
finboucle: 
	;=========FIN WHILE=========
	main endp
	end