	.file	"root.c"
	.text
	.globl	proche
	.type	proche, @function
proche:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC0(%rip), %xmm0
	andpd	%xmm1, %xmm0
	movsd	.LC1(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	jbe	.L7
	movsd	-16(%rbp), %xmm1
	movsd	.LC0(%rip), %xmm0
	andpd	%xmm1, %xmm0
	movsd	.LC1(%rip), %xmm1
	ucomisd	%xmm0, %xmm1
	seta	%al
	movzbl	%al, %eax
	jmp	.L5
.L7:
	movsd	-8(%rbp), %xmm0
	subsd	-16(%rbp), %xmm0
	movsd	.LC0(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	-8(%rbp), %xmm2
	movsd	.LC0(%rip), %xmm0
	andpd	%xmm2, %xmm0
	movsd	.LC2(%rip), %xmm2
	mulsd	%xmm2, %xmm0
	ucomisd	%xmm1, %xmm0
	seta	%al
	movzbl	%al, %eax
.L5:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	proche, .-proche
	.globl	moyenne
	.type	moyenne, @function
moyenne:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L9
.L10:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movsd	(%rax), %xmm0
	movsd	-16(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	addl	$1, -4(%rbp)
.L9:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L10
	pxor	%xmm0, %xmm0
	cvtsi2sd	-4(%rbp), %xmm0
	movsd	-16(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	moyenne, .-moyenne
	.globl	moyenne_positif
	.type	moyenne_positif, @function
moyenne_positif:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L13
.L14:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movsd	(%rax), %xmm0
	movsd	-16(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	addl	$1, -4(%rbp)
.L13:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movsd	(%rax), %xmm0
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jnb	.L14
	pxor	%xmm0, %xmm0
	ucomisd	-16(%rbp), %xmm0
	jp	.L15
	pxor	%xmm0, %xmm0
	ucomisd	-16(%rbp), %xmm0
	jne	.L15
	movsd	.LC4(%rip), %xmm0
	jmp	.L17
.L15:
	movsd	-16(%rbp), %xmm0
.L17:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	moyenne_positif, .-moyenne_positif
	.section	.rodata
	.align 8
.LC11:
	.string	"Pb moyenne.Attendu:%f Obtenu: %f \n"
	.align 8
.LC13:
	.string	"Pb moyenne_positif.Attendu: %f Obtenu: %f\n"
	.text
	.globl	test_moyenne
	.type	test_moyenne, @function
test_moyenne:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movsd	.LC5(%rip), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	.LC6(%rip), %xmm0
	movsd	%xmm0, -72(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	.LC8(%rip), %xmm0
	movsd	%xmm0, -56(%rbp)
	movsd	.LC9(%rip), %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	.LC10(%rip), %xmm0
	movsd	%xmm0, -40(%rbp)
	movsd	.LC4(%rip), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	.LC5(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	leaq	-80(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	moyenne
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	call	proche
	testl	%eax, %eax
	jne	.L20
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC11(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
.L20:
	movsd	.LC6(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	leaq	-80(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	moyenne
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	call	proche
	testl	%eax, %eax
	jne	.L21
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC11(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
.L21:
	movsd	.LC12(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	leaq	-80(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	moyenne
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	call	proche
	testl	%eax, %eax
	jne	.L22
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC11(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
.L22:
	movsd	.LC12(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	moyenne_positif
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	call	proche
	testl	%eax, %eax
	jne	.L23
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC11(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
.L23:
	movsd	.LC9(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	leaq	-80(%rbp), %rax
	addq	$24, %rax
	movq	%rax, %rdi
	call	moyenne_positif
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	-16(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	call	proche
	testl	%eax, %eax
	jne	.L24
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC11(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
.L24:
	movsd	.LC4(%rip), %xmm0
	movsd	%xmm0, -8(%rbp)
	leaq	-80(%rbp), %rax
	addq	$48, %rax
	movq	%rax, %rdi
	call	moyenne_positif
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movsd	.LC4(%rip), %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	call	proche
	testl	%eax, %eax
	jne	.L25
	movsd	-16(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	leaq	.LC13(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
.L25:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	test_moyenne, .-test_moyenne
	.globl	chaine_longueur_rec
	.type	chaine_longueur_rec, @function
chaine_longueur_rec:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L27
	movl	$0, %eax
	jmp	.L26
.L27:
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movq	%rax, %rdi
	call	chaine_longueur_rec
.L26:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	chaine_longueur_rec, .-chaine_longueur_rec
	.globl	chain_debute_par
	.type	chain_debute_par, @function
chain_debute_par:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L30
	movl	$1, %eax
	jmp	.L29
.L30:
	movq	-16(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L32
	movl	$0, %eax
	jmp	.L29
.L32:
	movq	-16(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	chain_debute_par
.L29:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	chain_debute_par, .-chain_debute_par
	.globl	chain_indice
	.type	chain_indice, @function
chain_indice:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L34
.L37:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	chain_debute_par
	testl	%eax, %eax
	je	.L35
	movl	-4(%rbp), %eax
	jmp	.L36
.L35:
	addl	$1, -4(%rbp)
.L34:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L37
	movl	$-1, %eax
.L36:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	chain_indice, .-chain_indice
	.globl	elever_au_cude
	.type	elever_au_cude, @function
elever_au_cude:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	pxor	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	movsd	.LC6(%rip), %xmm1
	call	pow@PLT
	cvttsd2si	%xmm0, %eax
	movl	%eax, -4(%rbp)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	elever_au_cude, .-elever_au_cude
	.section	.rodata
.LC14:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$5, -4(%rbp)
	leaq	-4(%rbp), %rax
	movq	%rax, %rdi
	call	elever_au_cude
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.section	.rodata
	.align 16
.LC0:
	.long	4294967295
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC1:
	.long	3834512688
	.long	724303662
	.align 8
.LC2:
	.long	3654794683
	.long	1037794527
	.align 8
.LC4:
	.long	0
	.long	-1074790400
	.align 8
.LC5:
	.long	0
	.long	1072693248
	.align 8
.LC6:
	.long	0
	.long	1073741824
	.align 8
.LC7:
	.long	0
	.long	1074266112
	.align 8
.LC8:
	.long	0
	.long	1074790400
	.align 8
.LC9:
	.long	0
	.long	1075052544
	.align 8
.LC10:
	.long	0
	.long	1075314688
	.align 8
.LC12:
	.long	0
	.long	1074528256
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
