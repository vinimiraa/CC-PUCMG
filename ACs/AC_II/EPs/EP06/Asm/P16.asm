# Escreva um programa que avalie a expressão: 
#     (x * y) / z. 
# Use
#     x = 1600000 (=0x186A00), 
#     y = 80000   (=0x13880), 
#     z = 400000 (=0x61A80). 
# Inicializar os registradores com os valores acima.

.data
    x: .word 0x186A00
    y: .word 0x13880
    z: .word 0x61A80

.text
.globl main
main:
    ori $s0, $0, 0x186A  # $s0 = 0x0000186A
    sll $s0, $s0, 4      # $s0 = 0x186A0
    
    ori $s1, $0, 0x1388  # $s1 = 0x00001388
    sll $s1, $s1, 4      # $s1 = 0x13880

    ori $s2, $0, 0x61A8  # $s2 = 0x000061A8
    sll $s2, $s2, 4      # $s2 = 0x61A80
    
    mult $s0, $s1        # $s0 * $s1
    mflo $t0             # 
    mfhi $t1             #

    div  $t0, $s2        # $t0 / $s2
    mflo $t1             # 

# EOF