.org 0x800

.data
	.comm array, 32 #buffer di grandezza 32 (unsigned) byte 
	.equ  len, 32 #dimensione vettore
.text 

 main:
	xorq %rax, %rax
	xorq %rcx, %rcx
	call mask
	hlt

 mask:
	pushq %rbp
	movq %rsp, %rbp
      .loop1:
	movb array(, %rcx, 1), %dl #RDX dim byte
	jmp .parity 
      .loop2:
	addb $1, %cl
	cmpb $len, %cl #RCX dim byte
	jz .skip
	jmp .loop1
      .force:
	leab 1(%cl), %r8d #%r8d contiene la posizione del bit da forzare(faccio +1 perché l'idx nel vettore parte da 0)
	movl $1, %r9d
	shll %r8d, %r9d  
	orl %r9d, %eax #forza a 1 il bit + significativo
	jmp .loop2
      .skip:
	ret
      .parity:
	shrb $1, %dl #capisco se il numero è dispari facendo uno shift a dx (me lo dice il bit - significativo)
	jnc .force #se ho scartato 1 allora era dispari
	jmp .loop2
