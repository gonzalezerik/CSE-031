.data
x:	.word 5
y:	.word 10
m:	.word 15
b:	.word 2
	.text
MAIN:	
la $t0, x
lw $s0, 0($t0)#x = $s0
la $t0, y
lw $s1, 0($t0)#y = $d1
		
		
add $a0, $zero, $s0	
add $a1, $zero, $s1	
jal SUB #call sum

add $t0, $t0, $t1
add $s0, $s0, $s1
addi $a0, $s1, 0 
li $v0, 1		 
syscall	
j END

		
SUM: 		
addi $sp, $sp -4
sw $ra, 0($sp)        
addi $sp, $sp -4
sw $s0, 0($sp)        
addi $sp, $sp -4
sw $s1, 0($sp)        
		
addi $a0, $a0, 1      
addi $a1, $a1, 1     
        	
		
add $a0, $zero, $s0	
add $a1, $zero, $s1	
jal SUB	#call sub
		
add $t0, $v0, $zero  

addi $a0, $a0, -2
move $t1, $a0 #shift content over
        	
addi $a1, $a1, -2        	
move $a0, $a1
        	
move $a1, $t1
        	
		
jal SUB #call sub

add $t1, $v0, $zero

lw $s1, 0($sp)       
addi $sp, $sp 4

lw $s0, 0($sp)        
addi $sp, $sp 4

lw $ra, 0($sp)        
addi $sp, $sp 4
        
jr $ra		
		
SUB:
addi $sp, $sp -4
sw $ra, 0($sp)		
		
sub $v0, $a0, $a1
lw $ra, 0($sp)        	
		
addi $sp, $sp 4
jr $ra
		
END:
