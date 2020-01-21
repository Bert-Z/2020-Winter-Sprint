	.file	"tailcall.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	_Z1ai
	.type	_Z1ai, @function
_Z1ai:
.LFB0:
	.cfi_startproc
	leal	(%rdi,%rdi), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z1ai, .-_Z1ai
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	_Z1bi
	.type	_Z1bi, @function
_Z1bi:
.LFB1:
	.cfi_startproc
	movl	%edi, %eax
	imull	%edi, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	_Z1bi, .-_Z1bi
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.section	.text.startup,"ax",@progbits
.LHOTB2:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	movl	$2, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE2:
	.section	.text.startup
.LHOTE2:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
