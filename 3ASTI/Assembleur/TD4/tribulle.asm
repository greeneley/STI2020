.386

.model flat


.DATA 
; déclaration d'un tableau statique
tab DWORD 1h,5h,3h,0h,0Ah,4h,6h,7h

.CODE
main proc
L0: ;------- WHILE (desorde)-----------------------------------
mov bx, 0               ; bx : la variable en_desordre
mov cx, LENGTHOF tab    ; directive pour récupérer la taille du tableau
dec cx				    ; pour balayer le tableau jusqu'à n-1
mov si,0				; indice sur le tableau (j)
	
    L1: ;----- FOR ---------- --------------------------------
		mov dx, tab[si]        ; transfert de la valeur tab[j]
		cmp ax, tab[si+2]  ; compare tab[j] et tab[j+1]
			;----- IF -------------------------------------
			jle L2             ; un saut si tab[j]<=tab[j+1]
			xchg ax, tab[si+2] ; echange des valeurs de tab[j] et tab[j+1]
			mov tab[si], ax    ; //
			mov bx,1           ; en_desorde = true
			;----FIN DE IF---------------------------------
		L2:add si,2            ; incrémentation du j, j=j+1
   loop L1					   ; boucle tant que cx >0 
	  ;------FIN de FOR------------------------------------
cmp bx,1
je L0
;----- FIN WHILE ----------------------------------------
mov ax, 0
main endp
END