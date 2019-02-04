.386
.model flat, stdcall
option casemap: none
;						; Inclusion des headers (définitions de fonctions)
include        \masm32\include\kernel32.inc
include        \masm32\include\msvcrt.inc
						; Inclusion des .lib (code des fonctions)
includelib    \masm32\lib\kernel32.lib
includelib    \masm32\lib\msvcrt.lib    ; => stdio.h 
 
.data
   
.code
 start:        ; Mettre c dans ecx
			main proc
            push offset FormatedData    ; 
            call crt_printf             ;
            push 0                     ; 
main endp
end                          