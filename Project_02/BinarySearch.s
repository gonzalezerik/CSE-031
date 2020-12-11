.data 

original_list: .space 100 
sorted_list: .space 100

str0: .asciiz "Enter size of list (between 1 and 25): "
str1: .asciiz "Enter one list element: "
str2: .asciiz "Content of original list: "
str3: .asciiz "Enter a key to search for: "
str4: .asciiz "Content of sorted list: "
strYes: .asciiz "Key found!"
strNo: .asciiz "Key not found!"

space: .asciiz " "
newLine: .asciiz "\n"

.text 

#This is the main program.
#It first asks user to enter the size of a list.
#It then asks user to input the elements of the list, one at a time.
#It then calls printList to print out content of the list.
#It then calls inSort to perform insertion sort
#It then asks user to enter a search key and calls bSearch on the sorted list.
#It then prints out search result based on return value of bSearch
main: 
	addi $sp, $sp -8
	sw $ra, 0($sp)
	li $v0, 4  
	la $a0, str0 
	syscall
	li $v0, 5	#Read size of list from user
	syscall
	move $s0, $v0
	move $t0, $0
	la $s1, original_list
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	#Read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	
	li $v0, 4 
	la $a0, str2 
	syscall 
	move $a0, $s1
	move $a1, $s0
	jal printList	#Call print original list
	
	jal inSort	#Call inSort to perform insertion sort in original list
	sw $v0, 4($sp)
	li $v0, 4 
	la $a0, str4 
	syscall 
	lw $a0, 4($sp)
	jal printList	#Print sorted list
	
	li $v0, 4 
	la $a0, str3 
	syscall 
	li $v0, 5	#Read search key from user
	syscall
	move $a2, $v0
	lw $a0, 4($sp)
	jal bSearch	#Call bSearch to perform binary search
	
	beq $v0, $0, notFound
	li $v0, 4 
	la $a0, strYes 
	syscall 
	j end
	
notFound:
	li $v0, 4 
	la $a0, strNo 
	syscall 
end:
	lw $ra, 0($sp)
	addi $sp, $sp 8
	li $v0, 10 
	syscall
	
	
#printList takes in a list and its size as arguments. 
#It prints all the elements in one line.
printList:
	#Your implementation of printList here	
	addi $sp, $sp -4
	sw $ra, 0($sp)
	
	#a0 = array address
	#a1 = array size
	move $t0, $a0 
	move $t1, $a1 
	
	ploop:

	
	lw $a0, 0($t0)
	li $v0, 1
	syscall
	
	addi $t0, $t0, 4 
	addi $t1, $t1, -1

	beq $t1, $zero, pend 
	j printComma

printComma: #prints a space
	la $t2, space
	move $a0, $t2
	li $v0, 4
	syscall
	
	j ploop
pend:
	la $t2, newLine
	move $a0, $t2
	li $v0, 4
	syscall	

	lw $ra, 0($sp) #restore $ra
	addi $sp, $sp 4
	
	jr $ra	

#inSort takes in a list and it size as arguments. 
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
	#Your implementation of inSort here
	addi $sp, $sp, -32
	sw $ra, 8($sp)
	sw $s0, 12($sp)
	sw $s1, 16($sp)
	sw $s2, 20($sp)
	sw $s3, 24($sp)
	sw $s4, 28($sp) 
	
	
	move $s0, $s1 # address of original array
	move $s1, $a1 # size of array
	addi $s2, $zero, 1 #i = 1
	
		arraycp:
		la $t0, original_list
		la $t1, sorted_list
		addi $t6, $t6, 0 # iterator
		# s1 is size
	
		arraycploop:
		#addi $t7, $t6, 1 # iterator is done when one less than size
		beq $s1, $t6, arraycpend
		
		lw $t2, ($t0)
		sw $t2, ($t1)
		
		#iterates pointers and iterator
		addi $t0, $t0, 4 
		addi $t1, $t1, 4
		addi $t6, $t6, 1
		
		j arraycploop

		arraycpend:
		la $t1, sorted_list
		move $s0, $t1
	
	
	iloop:
	beq $s2, $s1, iend # if i = arraySize then end
	
	#move $t0, $s0 # address of original array
	sll $t2, $s2, 2 # i * 4
	add $t3, $s0, $t2 # t3 = *array + offset
	lw $s3, ($t3) # s3 = array[i]
	addi $s4, $s2, -1 # j = i--
	
		jloop:
		# break if j < 0
		bltz $s4, jend # TODO confirm jend works correctly 
		
		# break if array[j] > key
		#addi $t0, $s4, 1 # t0 = j + 1
		move $a0, $s3 # a0 = s3 = key = array[i]
	
		la $t0, ($s0)
		sll $t2, $s4, 2
		add $t3, $t0, $t2 # t3 = array[j]
		lw $a1, ($t3)
		
	
		jal stringlt 
		
		move $t0, $v0
		beq $t0, $zero, jend 
		
		# c code:
		# array[j+1] = array[j];
		# j--
		la $t0, ($s0) 
		sll $t2, $s4, 2 
		add $t3, $t0, $t2
		lw $t4, 0($t3) # t4 = array[j]

		addi $t2, $s4, 1 # t2 = j + 1
		sll $t3, $t2, 2
		add $t1, $t3, $s0 # address of array[j+1]
		sw $t4, 0($t1) # array[j+1] = array[j]
		addi $s4, $s4, -1 # j--
		
		j jloop
		
		jend:
		
		#array[j+1] = key
		move $t0, $s4
		addi $t0, $t0, 1
		sll $t2, $t0, 2
		add $t1, $s0, $t2
		
		sw $s3, ($t1)
		
		
		addi $s2, $s2, 1 #i++
		j iloop
	iend:
	# restores a1
	move $a1, $s1
	
	lw $ra, 8($sp)
	lw $s0, 12($sp)
	lw $s1, 16($sp)
	lw $s2, 20($sp)
	lw $s3, 24($sp)
	lw $s4, 28($sp)
	addi $sp, $sp, 32
	
	
	
	
	la $v0, sorted_list # returns the address of the sorted array
	jr $ra

	
	
	
#string less than function: returns true if less than, false if greater than
stringlt: 

	move $t0, $a0 # t0 = a0 = s3 = key = array[i]
	move $t1, $a1 # array [j]


	sltloop:
	#lb $t2, ($t0) #TODO lb vs lw and 0($t0)
	#lb $t3, ($t1)
	
	#and $t4, $t2, $t3 # checks if null terminator
	#beq $t4, $zero, stringend
	
	blt $t0, $t1, iflt # jumps to less than if t0 < t1
	bge $t0, $t1, ifgt # jumps to greater than if t0 > t1
	
	#don't know why'd we do this, so I'm removing it
	#addi $t0, $t0, 1 # increments t0
	#addi $t1, $t1, 1 # increments t0
	j sltloop
	
	stringend:
	beq $t2, $zero, iflt # checks if x = 0
	j ifgt # returns false
	
	iflt: # returns true
	li $v0, 1
	j sltend	
	
	ifgt: # returns false
	li $v0, 0
	j sltend

	sltend:
	jr $ra
	
	
#bSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
bSearch:
	#Your implementation of bSearch here
	
	move $s0, $a0 # address sorted list
	move $s1, $a1 # right
	move $s2, $a2 # search key
	move $s3, $a3 # left
	li $s5, 0 # mid
	

	addi $s1, $s1, -1 # size/right
	

	bgt $s3, $s1, rightcheck
	nopegoback:
	blt $s1, $s3, bfalse 
	
	# mid = l + (r - l)/2
	sub $t0, $s1, $s3
	div $t0, $t0, 2
	add $s5, $s3, $t0
	
	# t1 = array[mid]
	sll $t1, $s5, 2
	add $t2, $s0, $t1
	lw $t1, ($t2)
	
	
	beq $t1, $s2, btrue
	
	# hacky code if l == 0 and r == 0 false
	li $t4, 0
	li $t5, 0
	
	slti $t4, $a3, 1
	slti $t5, $a1, 1
	
	add $t4, $t4, $t5
	li $t5, 2
	beq $t4, $t5, bfalse
	
	bgt $t1, $s2, bsgt # jumps to greater than if t0 > t1
	blt $t1, $s2, bslt # jumps to less than if t0 < t1
	
	bsgt:
	sub $a1, $s5, $s3
	j bSearch
	
	bslt:
	addi $a3, $s5, 1
	j bSearch
	
	btrue:
	li $v0, 1
	jr $ra
	bfalse:
	li $v0, 0
	jr $ra

	rightcheck:
		sll $t6, $s1, 2
		add $t6, $s0, $t6
		lw $t7, ($t6)
		beq $a2, $t7, btrue
		
	j nopegoback
	
