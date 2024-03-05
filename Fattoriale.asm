.org 0x800 

.data
    numero: .long 20 
    risultato: .fill 1, 8 

.text
 main:
    movl numero, %edi 
    call fattoriale 
    jnc .corretto 
    movl $-1, risultato 
    hlt     
  .corretto: %movl %eax, risultato 
    hlt

# Subroutine per la moltiplicazione 
# Parametri in %edi e %esi 
# Valore di ritorno in %eax 
# Se avviene overflow, ritorna con C=1 

 moltiplica: 
    xorl %eax, %eax 
  .loop: 
    testl %edi, %edi 
    jz .donemult 
    addl %esi, %eax 
    jc .donemult 
    subl $1, %edi         
    jmp .loop 
  .donemult: 
    ret
 fattoriale:
    xorl %eax, %eax
    push %edi
    cmpl $1, %edi # Se %eax = 1, esegui il passo base
    jnz .passoricorsivo
    movl %edi, %esi
    jmp .passobase
  .passoricorsivo:
    subl $1, %edi
    call fattoriale # Chiama la stessa subroutine
    jnc .nooverflow
    pop %edi # Con overflow, tolgo dallo stack i valori salvati
    jmp .doneFATT
  .nooverflow:
    movl %eax, %esi
  .passobase:
    pop %edi
    call moltiplica # %eax = n * fatt(n-1)
  .doneFATT:
    ret


