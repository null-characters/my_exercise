	.file	"eor_lear.c"
	.text
	.globl	arr_test
	.data
	.align 32
arr_test:
	.long	0
	.long	0
	.long	1
	.long	6
	.long	6
	.long	8
	.long	1
	.long	8
	.long	8
	.long	0
	.long	0
	.long	9
	.globl	arr_test_return
	.bss
	.align 4
arr_test_return:
	.space 1
	.section .rdata,"dr"
.LC0:
	.ascii "no charter\12\0"
.LC1:
	.ascii "%d\12\0"
	.text
	.globl	xor_array_4_one
	.def	xor_array_4_one;	.scl	2;	.type	32;	.endef
	.seh_proc	xor_array_4_one
xor_array_4_one:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$0, 24(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rcx
	call	printf_s
	jmp	.L1
.L2:
	cmpl	$1, 24(%rbp)
	jne	.L4
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf_s
	jmp	.L1
.L4:
	movl	$0, -8(%rbp)
	jmp	.L5
.L6:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	xorl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L5:
	movl	-8(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L6
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf_s
	nop
.L1:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	xor_array_4_two
	.def	xor_array_4_two;	.scl	2;	.type	32;	.endef
	.seh_proc	xor_array_4_two
xor_array_4_two:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$0, 24(%rbp)
	jne	.L8
	leaq	.LC0(%rip), %rcx
	call	printf_s
	jmp	.L7
.L8:
	cmpl	$1, 24(%rbp)
	jne	.L10
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf_s
	jmp	.L7
.L10:
	movl	$0, -8(%rbp)
	jmp	.L11
.L12:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	xorl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L11:
	movl	-8(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L12
	movl	-4(%rbp), %eax
	negl	%eax
	andl	-4(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L13
.L15:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	andl	-20(%rbp), %eax
	testl	%eax, %eax
	je	.L14
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	xorl	%eax, -12(%rbp)
.L14:
	addl	$1, -16(%rbp)
.L13:
	movl	-16(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L15
	movl	-4(%rbp), %eax
	xorl	-12(%rbp), %eax
	movl	%eax, -24(%rbp)
.L7:
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	singleNumber
	.def	singleNumber;	.scl	2;	.type	32;	.endef
	.seh_proc	singleNumber
singleNumber:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	$8, %ecx
	call	malloc
	movq	%rax, -24(%rbp)
	movq	32(%rbp), %rax
	movl	$2, (%rax)
	cmpl	$0, 24(%rbp)
	jne	.L17
	movq	-24(%rbp), %rax
	jmp	.L18
.L17:
	cmpl	$1, 24(%rbp)
	jne	.L19
	movq	16(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	addq	$4, %rax
	movl	$0, (%rax)
	movq	-24(%rbp), %rax
	jmp	.L18
.L19:
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L20
.L21:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	xorl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L20:
	movl	-8(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L21
	cmpl	$-2147483648, -4(%rbp)
	je	.L22
	movl	-4(%rbp), %eax
	negl	%eax
	andl	-4(%rbp), %eax
	jmp	.L23
.L22:
	movl	-4(%rbp), %eax
.L23:
	movl	%eax, -28(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L24
.L26:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	andl	-28(%rbp), %eax
	testl	%eax, %eax
	je	.L25
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	xorl	%eax, -12(%rbp)
.L25:
	addl	$1, -16(%rbp)
.L24:
	movl	-16(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L26
	movq	-24(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	leaq	4(%rax), %rdx
	movl	-12(%rbp), %eax
	xorl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	movq	-24(%rbp), %rax
.L18:
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC2:
	.ascii "%d, %d\12\0"
.LC3:
	.ascii "\12\347\250\213\345\272\217\350\277\220\350\241\214\344\272\206%ld\345\276\256\347\247\222\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	leaq	-16(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	mingw_gettimeofday
	movl	$12, -4(%rbp)
	movl	-4(%rbp), %eax
	leaq	arr_test_return(%rip), %r8
	movl	%eax, %edx
	leaq	arr_test(%rip), %rcx
	call	singleNumber
	movl	4+arr_test_return(%rip), %edx
	movl	arr_test_return(%rip), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	leaq	-24(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rcx
	call	mingw_gettimeofday
	movl	-24(%rbp), %edx
	movl	-16(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$1000000, %eax, %eax
	movl	-20(%rbp), %ecx
	movl	-12(%rbp), %edx
	subl	%edx, %ecx
	movl	%ecx, %edx
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf_s;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	mingw_gettimeofday;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
