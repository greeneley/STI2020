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

;===========================================================
; De printf duoc nhieu chuoi, quan trong nhat la khai bao chuoi, cau truc nhu vay, so 10 la lenh \n, 0 la lenh print lien tiep
 msg byte 'Hello, World!',10,0  
 FormatedData    byte    "tour %d",10, 0
 .code
 
; point d'entrée
start:        ; Mettre c dans ecx
			main proc
            push offset FormatedData    ; 
            call crt_printf             ;
			push offset msg ;
			call crt_printf
;
main endp
end                          