# Laboratory Exercise 3, Home Assignment 1
# Written by Jan Eric Larsson , 27 October 1998
# include <iregdef.h>
.set noreorder
.text
.globl start
.ent start
.data
resultstring:.asciiz "The result is %d\n"
plus:.asciiz " + "
newline:.asciiz "\n"
.text
start:	jal		getdigit		#Get first operand
		nop
		addi	s0, v0, 0x0		#Move digit to s0
		la		a0, plus		#load address of " + " string
		jal		printf			#print " + "
		nop
		jal		getdigit		#Get second operand
		nop
		addu	a1, s0, v0		#compute sum of operands
		la		a0, newline		#load address of newline string
		jal		printf			#print newline
		nop
		la		a0, resultstring#load resultstring address
		jal		printf			#print the result
		nop
		j		start			#repeat ad infinitum
.end start
		
.ent getdigit
getdigit: add	t1, ra, zero	#save return address
		jal	getchar				#Get ascii code
		nop
		add		a0, v0, zero	#move character to a0 for putchar
		addi	t2, v0, -0x30	#Convert to decimal digit and store in t2 because putchar modifies v0
		jal		putchar			#print recieved digit
		nop
		add		v0, t2, zero	#move back into return variable register
		jr		t1				#return
		nop						
.end getdigit
