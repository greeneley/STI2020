.386 ; processeur 32 bits

.model flat, stdcall ; 

includelib "D:\Soft\StudioVisual2012\VC\lib\msvcrtd.lib"

extern  printf    :   proc

.data
msg BYTE "Hello World"

.code
main proc
lea eax, msg
call afficher
main endp 

;******** PROCEDURE afichage de message ********************;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Affiche un méssage                                        ;
; --> Paramètres d'entrée : adresse du début du message     ;
;                            dans eax                        ;    
; <-- retour: message affiché dans la console                ;
;-----------------------------------------------------------;
afficher proc
	push    eax
	call    printf
	pop eax
	ret
afficher endp 
end
