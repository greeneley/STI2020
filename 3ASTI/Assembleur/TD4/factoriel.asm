Title calcul du factoriel par recursivit�

.386 ; processeur 32 bits

.model flat ; mod�le de la m�moire

.data
tab DWORD ?

.code
;************ PROCEDURE MAIN ************;
main proc
; initialisation des param�tres de la proc�dure facto
;-----------
mov eax, 5   
mov ebx, eax
mov ecx, 0
lea esi, tab
;------------
call facto
mov eax, eax  ; facultatif pour ne pas sortir du programme
ret
main endp
;************ FIN PROCEDURE MAIN ********;

;******************* PROCEDURE FACTO ***********************;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; proc�dure pour calcul du factoriel						;
; d'un nombre entier N, stockage des factoriels				;
; dans un tableau											;	
; utilisation de la recursivit�								;
; --> Param�tres d'entr�e :- le nombre N dans eax et ebx	;	
;                           - l'adresse du tableau dans esi	;
;							- initialiser ecx = 0			;
; <-- retour: - factoriel de N dans eax						;
;			   - les valeurs dans un tableau point� � la fin;
;				 par esi									;	
;			   - la taille du tableau ecx					;	
;-----------------------------------------------------------;
facto proc 
dec ebx            ; N=N-1
mov [esi],eax      ; Stockage des resultats : N, N*(N-1), (N-1)*(N-2),...
add esi, 4         ; incr�menter l'indice du tableau
inc ecx            ; incrimenter ecx  pour la taille du tableau
cmp ebx,1          ; si le dernier nombre !=0
je fin             ; si le dernier nombre == 0 aller � fin
mul ebx            ; N*(N-i), (N-1)*(N-2),..., r�sultat dan eax
call facto         ; appel recursive de la proc�dure facto
fin:ret            ; retour de la fonction facto
facto endp
;************ FIN DE LA PROCEDURE FACTO *********************;

end
