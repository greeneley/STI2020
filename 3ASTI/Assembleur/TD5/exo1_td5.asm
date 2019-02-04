TITLE      comparaison de chaines  TD5 exo1 
.486
; mod�le de memoire utilis�e, un "data segment" et un "code segment"
.model flat 




; definition des constantes


;;;;;;;;segment de donn�es;;;;;;;;
.data 
String1 BYTE "AZERTYU"
String2 BYTE "AZERTYUI"
message1 BYTE "chaines identiques$"
message2 BYTE "chaines differentes$"

;;;;;;;;segment du code;;;;;;;;;;; 
.code
main PROC                         
        lea esi, String1    ; l'adresse du d�but String1 dans SI	
		lea edi, String2    ; l'adresse du d�but String2 dans DI
        mov ecx, LENGTHOF String2  ; taille de la cha�ne	
		call compareChaines   ; appel proc�dure, comparaison de deux chaines 
        cmp ax, 1                 ; Ax param�tre de retour, si AX=1, les deux cha�nes sont identiques 
		jnz e1                    ; si non en passe � e1
		jmp affichage             ; saut pour affichage du message 1
e1:     cmp ax, 2                 ; si AX=2 les deux chaines sont diff�rentes
		jnz exit                  ; si non on quite 
affichage:  
		call afficher		      ; appel de la proc�dure d'affichage
jmp exit		
main ENDP	

;//////////////////////////////////	
compareChaines PROC
; compare deux cha�nes point�es par ESI et EDI vers 
; re�oit ESI, EDI et la taille d'une chaine dans cx
; renvoi AX = 1 si les deux chaines sont �gaux, AX = 2 si non
	mov ax, 0     ; initialisation de AX
	cld           ; modification du flag, pour incrementation SI et DI lors de l'utilisation de cmpsb
	repe cmpsb    ; compare deux chaines point�es par SI et DI, r�p�tition tant que c'est �gale 
	jnz e1        ; si les deux cha�nes ne sont pas identiques branchement vers e1 
    mov ax, 1 	  ; AX := 1 si les deux cha�nes sont identiques  	
	jmp e2        ; si non saut vers e2
e1: 
	mov ax, 2     ; Ax :=2 les deux cha�nes ne sont pas identiques
e2:    
ret		
compareChaines ENDP
;//////////////////////////////////


;///////////////////////////////////
afficher PROC
; affiche une cha�ne de caract�res 
; re�oit l'adresse de debut de la cha�ne dans DX
;mov ah, 09h   ; pour affichage lors de l'appel DOS 
;int 21h       ; interruption logiciel : appel DOS
ret
afficher ENDP
;////////////////////////////////////

exit:
END


