				; Declare external C functions, to be called
        extern	printf		
	extern	__isoc99_scanf
        extern	malloc		
        extern	free		

        SECTION .data		; Data section, initialized variables

fmt_int:   	db "%d", 0	
fmt_char:   	db "%c", 0	
fmt_char_in:	db "%c", 0	
fmt_cr:    	db 10, 0	
fmt_string:    	db "%s", 0	

        SECTION .text           ; Code section.

	global main	        ; the standard gcc entry point

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Runtime x86
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Usage:
; push int
; call print_int
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_int:			
	push 	rbp
	mov  	rbp,rsp
	
	mov	rdi,fmt_int	; format for printf
	mov	rsi,[rbp+16]    ; first parameter for printf
	mov	rax,0		; no xmm registers
        call    printf		; Call C function

	pop	rbp		; restore stack			
	ret	8		; return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Usage:
; push char
; call print_char
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_char:
	push 	rbp
	mov  	rbp,rsp
	
	mov	rdi,fmt_char	; format for printf
	mov	rsi,[rbp+16]    ; first parameter for printf
	mov	rax,0		; no xmm registers
        call    printf		; Call C function

	pop	rbp		; restore stack			
	ret	8		; return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Usage:
; call print_newline
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_newline:	
	mov	rdi,fmt_cr	; format for printf
	mov	rsi,fmt_cr      ; first parameter for printf
	mov	rax,0		; no xmm registers
        call    printf		; Call C function
	ret			; return
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Usage:
; push @base_string
; call print_string
; string should be ASCIIZ 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
print_string:
        push    rbp
	mov  	rbp,rsp
	
	mov	rdi,fmt_string	; format for printf
	mov	rsi,[rbp+16]    ; first parameter for printf
	mov	rax,0		; no xmm registers
        call    printf		; Call C function

	pop	rbp		; restore stack
	ret	8		; return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Usage:
; call input_char
; returns rax: input char 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
input_char:	
        push    rbp
	mov  	rbp,rsp
	sub	rsp,8		; allocate space for input char
	
	mov	edi,fmt_char_in	; format for scanf
	lea	rsi,[rbp-8]
	mov	eax,0
        call    __isoc99_scanf	; call scanf
	
	mov	rax,[rbp-8]	; get the result in rax
	and	rax,255		; keep the 8 least significant bits

	push	rax		; save the result
	mov	edi,fmt_char_in	; 
	lea	rsi,[rbp-8]
	mov	eax,0
        call    __isoc99_scanf	; flush cr
	pop	rax		; restore the result
	
	mov	rsp,rbp
	pop	rbp		; restore stack
	ret			; return

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Usage:
; push size
; call _malloc
; returns rax: base address
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_malloc:
	push	rbp
	mov	rbp,rsp
	
	mov 	rdi,[rbp+16]
	call 	malloc
	; rax is a pointer to the allocated space

	mov	rbx,[rbp+16]
	cmp	rbx,8
	je 	end_malloc	; scalar type (one word) => exit

	;;  prepare allocated memory for digcc struct types
	mov 	rdi,rax	
	add	rdi,rbx
	sub	rdi,8		; rdi points to the last word
	mov	[rax],rdi	; first word := pointer to last word	
	
end_malloc:	
	pop	rbp
	ret	8

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Usage:
; push  @base
; push size //compatibility with digmips
; call _free
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_free:
	push	rbp
	mov	rbp,rsp

	mov	rdi,[rbp+24]
	call 	free	

	pop	rbp
	ret	16

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Main program
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

