.data
	input: .asciiz "\nPlease enter a number:  "
	negSum: .asciiz "\nSum of negative numbers: "
	posSum: .asciiz "\nSum of positive numbers is: "

	
.text 
#input
a:	li $v0, 4
	la $a0, input
	syscall
	li $v0, 5
	syscall
 	move $t0, $v0
 	

 	blt $t0, $zero, n
 	bgt $t0, $zero, p
 	beq $t0, $zero, end
 	

 n:	add $t1, $t1, $t0
 	j a
 	
 p:	add $t2, $t2, $t0
 	j a
 	
 end:	li $v0, 4
 	la $a0, posSum
	syscall
	li $v0, 1
	la $a0, ($t2)
	syscall
	li $v0, 4
 	la $a0, negSum
	syscall
	li $v0, 1
 	la $a0, ($t1)
	syscall
	