.org 0x800

.data 
	v: .word 3, 6, 9, 1, 74
	.equ n, 5

.text

main:
	xorq %rdx, %rdx
	xorq %rcx, %rcx
	call ricerca
	hlt
	
ricerca:
	pushq %rbp
	movq %rsp, %rbp
	movw v(, %rcx, 2), %dx
	addw $1, %cx
     .loop: 
	cmpw $n, %cx 
	jz .skip
	cmpw v(, %rcx, 2), %dx
	jc .set # unsigned
	addw $1, %cx
	jmp .loop 
     .skip:
	ret
     .set:
	movw v(, %rcx, 2), %dx
	addw $1, %cx
	jmp .loop
