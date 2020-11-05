.data
str1: .asciiz "Please enter an integer: "

.text

main: 		addi $sp, $sp, -4	
		li $v0, 4       # ask for user input
		la $a0, str1
		syscall 
		
		li $v0, 5 
		syscall 
		move $a0, $v0   
		addi $v0, $zero, 0  
		
		jal recursion	# Call recursion function
		
		sw $v0, 0($sp)  
		lw $a0, 0($sp)
		
		li $v0, 1		 
		syscall	
		
		j end		


recursion:	addi $sp, $sp, -12	
		sw $ra, 8($sp)  
		
		# is m 10
		addi $t0, $zero, 10
		bne $t0, $a0, not_ten

		addi $v0, $v0, 2 
		j END_COND
			
not_ten:		addi $t0, $zero, 11 # is m is 11 
		bne $t0, $a0, not_eleven
		
		addi $v0, $v0, 1
		
		j END_COND		

not_eleven:	sw $a0, 4($sp) 	
		addi $a0, $a0, 2 
		
		jal recursion	# recursion(m + 2)
		lw $a0, 4($sp)   
		
		addi $a0, $a0, 1 
		jal recursion	# recursion(m + 1)
		
		lw $a0, 4($sp) 
		add $v0, $v0, $a0  
		j END_COND
		
		
END_COND:	lw $ra, 8($sp) 	#return to main
		addi $sp, $sp, 12	
		jr $ra

end:		addi $sp, $sp 4	
		li $v0, 10 
		syscall
