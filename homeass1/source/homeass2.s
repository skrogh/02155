#include <iregdef.h>
.set noreorder
.text 
.globl start
.ent start

start:  jal		getchar			#Blocking call to get character
		nop						#must nop after jump
		add		a0, v0, zero	#transfer to a0 for putchar 
		slti	s0, a0, 0x61	#check character code < a in ascii
		beq		s0,	zero, lcase #branch to lowercase handling	
		nop

print:	jal		putchar			#print char in a0 on console
		nop
		j		start			#Repeat ad infinitum
		.end	start			

lcase:	slti	s0, a0, 0x7B	#check that v0 is actually a lowercase letter
		beq		s0, zero, print #if not then print the character
		nop
		addi	a0, a0, -0x20	#else convert to uppercase
		j		print			#and print
		nop
		
