TITLE      comparaison de chaines  TD5 exo1 
.486
; modèle de memoire utilisée, un "data segment" et un "code segment"
.model flat 




; definition des constantes


;;;;;;;;segment de données;;;;;;;;
.data 
String1 BYTE "AZERTYU"
String2 BYTE "AZERTYUI"
message1 BYTE "chaines identiques$"
message2 BYTE "chaines differentes$"

;;;;;;;;segment du code;;;;;;;;;;; 
.code
main PROC                         
        lea esi, String1    ; l'adresse du début String1 dans SI	
		lea edi, String2    ; l'adresse du début String2 dans DI
        mov ecx, LENGTHOF String2  ; taille de la chaîne	
		call compareChaines   ; appel procédure, comparaison de deux chaines 
        cmp ax, 1                 ; Ax paramètre de retour, si AX=1, les deux chaînes sont identiques 
		jnz e1                    ; si non en passe à e1
		jmp affichage             ; saut pour affichage du message 1
e1:     cmp ax, 2                 ; si AX=2 les deux chaines sont différentes
		jnz exit                  ; si non on quite 
affichage:  
		call afficher		      ; appel de la procédure d'affichage
jmp exit		
main ENDP	

;//////////////////////////////////	
compareChaines PROC
; compare deux chaînes pointées par ESI et EDI vers 
; reçoit ESI, EDI et la taille d'une chaine dans cx
; renvoi AX = 1 si les deux chaines sont égaux, AX = 2 si non
	mov ax, 0     ; initialisation de AX
	cld           ; modification du flag, pour incrementation SI et DI lors de l'utilisation de cmpsb
	repe cmpsb    ; compare deux chaines pointées par SI et DI, répétition tant que c'est égale 
	jnz e1        ; si les deux chaînes ne sont pas identiques branchement vers e1 
    mov ax, 1 	  ; AX := 1 si les deux chaînes sont identiques  	
	jmp e2        ; si non saut vers e2
e1: 
	mov ax, 2     ; Ax :=2 les deux chaînes ne sont pas identiques
e2:    
ret		
compareChaines ENDP
;//////////////////////////////////


;///////////////////////////////////
afficher PROC
; affiche une chaîne de caractères 
; reçoit l'adresse de debut de la chaîne dans DX
;mov ah, 09h   ; pour affichage lors de l'appel DOS 
;int 21h       ; interruption logiciel : appel DOS
ret
afficher ENDP
;////////////////////////////////////

exit:
END


