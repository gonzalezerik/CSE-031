.data 

n: .word 25

str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to \n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"
input: .asciiz "Enter a number: "


.text

	la $t1, n
	lw $t1, 0($t1)
	li $v0, 4
	la $a0, input
	syscall
	li $v0, 5
	syscall
 	move $t0, $v0
	
	#Step 7
        gtc:slt $s0, $t0, $t1
	beq $s0, $zero, greatert
	bne $s0, $zero, ltec
	
	li $v0, 10
	syscall
	
        greatert:li $v0, 4
	la $a0, str3
	syscall

	#less than or eqaul to
        ltec:	beq $t0, $t1, lesste
	bne $t0, $t1, lesste
        lesste:	slt $s0,$t0, $t1
	bne $s0, $zero, lesst
 	
 	li $v0, 10 
	syscall
	 
        lesst:li $v0, 4
 	la $a0, str2
	syscall