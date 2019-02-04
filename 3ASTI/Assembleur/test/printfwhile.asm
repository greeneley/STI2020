.386
.model flat, stdcall
option casemap: none
;						; Inclusion des headers (définitions de fonctions)
include        \masm32\include\kernel32.inc
include        \masm32\include\msvcrt.inc
						; Inclusion des .lib (code des fonctions)
includelib    \masm32\lib\kernel32.lib
includelib    \masm32\lib\msvcrt.lib    ; => stdio.h 
 
 
						; début de la section data
.data
						; Déclaration d'une chaîne de caractère correspondant à l'argument 1 de printf
FormatedData    db    "tour %d",10, 0    ; le 10 correspond à "\n", ou retour à la ligne
 
						; Déclaration de notre variable 'c' initialisée à 1
VariableC        dd    1
 
						; Début de section code
.code
 
; point d'entrée
start:        ; Mettre c dans ecx
			main proc
            mov ecx, VariableC
 
boucle:                                    ; label pour marquer le début de boucle
            cmp ecx, 0Ah                ; On compare ecx à 10   => A=10    Si en C on a "<=" alors en assmebleur on a ">"
            ja fin                        ; ecx > 10 ? On va à la fin de la boucle
            push ecx                    ; Sauvegarde d'ecx
            push ecx                    ; sinon, on empile nos arguments...
            push offset FormatedData    ; ... pour appeler la fonction...
            call crt_printf                ; printf()
            mov ecx, [esp+8]            ; Restauration d'ecx
            inc    ecx                        ; on incrémente ecx (ecx = ecx + 1)
            jmp boucle                    ; on revient au début de la boucle
fin:                                    ; label pour marquer les instructions en dehors de la boucle.
           ; dec ecx                        
           ; mov VariableC, ecx            ; On replace ecx dans VariableC
            push 0                        ; On quitte le programme.
            call ExitProcess

main endp
end                                ; Fin du code.

printf(a,v,b,c)
push a esp +12
push v esp +8
push b esp +4
push c esp
call printf


add ecx,1 = inc ecx
sub ecx,1 = dec ecx




pour un IF :

ebx = X

mov eax,op1			mov eax,op1
cmp eax,op2			mov eax,op2
jne ELSE			je IF
mov ebx,1			mov ebx,2
jmp FINIF			jmp FINIF
ELSE :				IF :
mov ebx,2			mov ebx,1
FINIF :				FINIF :


