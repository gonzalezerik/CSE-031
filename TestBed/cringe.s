.data
str1: .asciiz "Please enter an integer: "


        .text
main: 		addi $sp, $sp, -4	
		li $v0, 4       # ask for user input
		la $a0, str1
		syscall 
		
		li $v0, 5 
		syscall # value entered by user stored in $v0
		move $a0, $v0   
		addi $v0, $zero, 0  # clear v0 since it is return value
		
		jal recursion	# Call recursion(x)
		
		sw $v0, 0($sp)  # prints final return value
		lw $a0, 0($sp)
		
		li $v0, 1		 
		syscall	
		
		j end		# Jump to end of program


recursion:	addi $sp, $sp, -12	# Push stack frame for local storage
		sw $ra, 8($sp)  # storing return address in stack frame
		
		# check if m is 10
		addi $t0, $zero, 10
		bne $t0, $a0, not_ten

		addi $v0, $v0, 2 
		j end_recur
			
not_ten:	addi $t0, $zero, 11 # checks if m is 11 
		bne $t0, $a0, not_eleven
		
		addi $v0, $v0, 1
		
		j end_recur		

not_eleven:	sw $a0, 4($sp) 	
		addi $a0, $a0, 2 # prepare m + 2
		
		jal recursion	# Call recursion(m + 2)
		lw $a0, 4($sp)   #loads first return value
		
		addi $a0, $a0, 1 # prepare m + 1
		jal recursion	# Call recursion(m + 1)
		
		lw $a0, 4($sp) # loads first return value
		add $v0, $v0, $a0  # adds all values together
		j end_recur
		
end_recur:	
		lw $ra, 8($sp) 	# retrieve value for program to return to main
		addi $sp, $sp, 12	# Pop stack frame 
		jr $ra

end:		addi $sp, $sp 4	# Moving stack pointer back (pop the stack frame)
		li $v0, 10 
		syscall
