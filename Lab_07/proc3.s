.data
x: .word 5
y: .word 10
p: .word 0
q: .word 0

.text 

MAIN:	la $t0, x #x= $s0
	lw $s0, 0($t0)
	la $t0, y #y = $s1
	lw $s1, 0($t0)
	
	add $a0, $a0, $s0
	add $a1, $a1, $s1
	jal SUB
	
	add $s1, $a0, $a1
	add $a0, $s1, $s0
	li $v0, 1		 
	syscall	
	j END
	

SUM:	addi $t0, $a1, 1
	addi $t1, $a0, 1
	jal SUB
	
	la $t0, p
	lw $s0, 0($t0)
	add $s0, $s0, $v0	
	subi $t0, $a0, 1
	subi $t1, $a1, 1
	jal SUB
	
	la $t0, q
	lw $s1, 0($t0)
	add $s1, $s1, $v0
	add $s0, $s0, $s1
	addi $ra, $zero, 4194340 #to reach counter variable
	jr $ra
	
SUB:	sub $v0, $t1, $t0
	jr $ra
	
END: