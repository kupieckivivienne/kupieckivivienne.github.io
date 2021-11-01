	.file	"div.c"
	.text
	.globl	div_qr
	.type	div_qr, @function
div_qr:
.LFB0:
	.cfi_startproc
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	movq	%rdx, %rcx 
	movl	%edi, %eax
	cltd
	idivl	%esi
	movl	%edx, (%rcx)
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	div_qr, .-div_qr
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
