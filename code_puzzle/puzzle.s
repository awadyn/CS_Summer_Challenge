	.file	"puzzle.c"
	.text
	.comm	list,20,16
	.comm	median,4,4
	.comm	median_index,4,4
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	print_list
	.type	print_list, @function
print_list:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	list(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L2:
	cmpl	$4, -4(%rbp)
	jle	.L3
	movl	$10, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	print_list, .-print_list
	.section	.rodata
.LC1:
	.string	"Enter 5 integers:"
.LC2:
	.string	"%d %d %d %d %d"
	.text
	.globl	get_list
	.type	get_list, @function
get_list:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	16+list(%rip), %rsi
	leaq	12+list(%rip), %rcx
	leaq	8+list(%rip), %rdx
	leaq	4+list(%rip), %rax
	movq	%rsi, %r9
	movq	%rcx, %r8
	movq	%rdx, %rcx
	movq	%rax, %rdx
	leaq	list(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	cmpl	$5, %eax
	jne	.L5
	movl	$0, %eax
	jmp	.L6
.L5:
	movl	$-1, %eax
.L6:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	get_list, .-get_list
	.globl	int_compare
	.type	int_compare, @function
int_compare:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jg	.L8
	movl	$0, %eax
	jmp	.L9
.L8:
	movl	$1, %eax
.L9:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	int_compare, .-int_compare
	.globl	sort_list
	.type	sort_list, @function
sort_list:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	int_compare(%rip), %rcx
	movl	$4, %edx
	movl	$5, %esi
	leaq	list(%rip), %rdi
	call	qsort@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	sort_list, .-sort_list
	.globl	get_median
	.type	get_median, @function
get_median:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$2, median_index(%rip)
	movl	median_index(%rip), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	list(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, median(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	get_median, .-get_median
	.section	.rodata
	.align 8
.LC3:
	.string	"Successfully read integer list: "
.LC4:
	.string	"Unsuccessful list entry."
.LC5:
	.string	"Successfully sorted list: "
.LC6:
	.string	"Unsuccessful list sort."
.LC7:
	.string	"\n Median: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %eax
	call	get_list
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L14
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	call	print_list
	jmp	.L15
.L14:
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
.L15:
	movl	$0, %eax
	call	sort_list
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L16
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	call	print_list
	jmp	.L17
.L16:
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
.L17:
	movl	$0, %eax
	call	get_median
	movl	median(%rip), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
