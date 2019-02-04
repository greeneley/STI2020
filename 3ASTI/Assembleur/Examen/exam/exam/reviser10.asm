.386
.model flat, stdcall
option casemap: none
;
include        \masm32\include\kernel32.inc
include        \masm32\include\msvcrt.inc
includelib    \masm32\lib\kernel32.lib
includelib    \masm32\lib\msvcrt.lib    ; => stdio.h
.data
string1 byte "AZERTYUI"
string2 byte "AZERTYUI"
mess1 byte "deux chaines ensembles",10,0
mess2 byte "deux chaines diffences",10,0
.code
start:
	main proc
	mov ecx, lengthof string1
	lea esi, string1
	lea edi, string2
	call compare
	cmp ax,1
	je affichermess1
	jmp affichermess2
affichermess1:
	push offset mess2
	call crt_printf
	jmp quit
affichermess2:
	push offset mess1
	call crt_printf
	jmp quit
	main endp
;======================
compare proc
	cld
	repe cmpsb
	jecxz l1
	mov ax,1; si ax=1 => deux chaines diffences
	ret
l1:
	mov ax,0; si ax=0 => deux chaines pareils
	ret
compare endp
;;;
quit:
end