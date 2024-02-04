	.file	"select_sorting.c"
	.text
	.globl	arr_test
	.data
	.align 16
arr_test:
	.long	2
	.long	7
	.long	1
	.long	9
	.long	6
	.text
	.globl	select_sortint_func
	.def	select_sortint_func;	.scl	2;	.type	32;	.endef
	.seh_proc	select_sortint_func
select_sortint_func:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	32(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	addl	$1, -8(%rbp)
.L2:
	movl	-8(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L3
	movl	$0, -12(%rbp)
	jmp	.L4
.L9:
	addl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jge	.L5
	movl	-4(%rbp), %eax
	movl	%eax, -16(%rbp)
	jmp	.L6
.L8:
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rcx
	movq	32(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L7
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -20(%rbp)
	movl	-16(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	32(%rbp), %rax
	addq	%rax, %rdx
	movl	-16(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	32(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rdx), %edx
	movl	%edx, (%rax)
	movl	-16(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	32(%rbp), %rax
	addq	%rdx, %rax
	movl	-20(%rbp), %edx
	movl	%edx, (%rax)
.L7:
	subl	$1, -16(%rbp)
.L6:
	cmpl	$0, -16(%rbp)
	jg	.L8
.L5:
	addl	$1, -12(%rbp)
.L4:
	movl	24(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jl	.L9
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\11\0"
.LC1:
	.ascii "\12\0"
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
	movl	$5, -12(%rbp)
	movl	-12(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L11
.L12:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	arr_test(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf_s
	addl	$1, -4(%rbp)
.L11:
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L12
	leaq	.LC1(%rip), %rcx
	call	printf_s
	movq	-24(%rbp), %rdx
	movl	-12(%rbp), %eax
	movq	%rdx, %r8
	movl	%eax, %edx
	leaq	arr_test(%rip), %rcx
	call	select_sortint_func
	movl	$0, -8(%rbp)
	jmp	.L13
.L14:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf_s
	addl	$1, -8(%rbp)
.L13:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L14
	leaq	.LC1(%rip), %rcx
	call	printf_s
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	printf_s;	.scl	2;	.type	32;	.endef
