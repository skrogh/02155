# Laboratory Exercise 3, Home Assignment 1
# Written by Jan Eric Larsson , 27 October 1998
# include <iregdef.h>
.set noreorder
.text
.globl start
.ent start
start:	jal		wait # Wait for button click
		nop
		lui		s0, 0xbf90 # Load switch port address
		lb		s1, 0x0(s0) # Read first number from switches
		nop
		jal		wait # Wait for button click
		nop
		lb		s2, 0x0(s0) # Read second number from switches
		nop
		addu	s3, s1, s2 # Perform an arithmetic operation
		sb 		s3, 0x0(s0) # Write the result to LEDs
		b start # Repeat all over again
		nop
		### Add code for wait subroutine here ! ###
.end start
.ent wait
wait:	# Wait for button pressed and depressed
		lui 	t0, 0xbfa0 # Load switch port address
		li 		t1, 0x01 # Load bitmask
waitPs:	# Wait for button press state
		lb 		t2, 0x0(t0) # Read byte from port
		and 	t3, t2, t1 # Apply bitmask, put in another register due to bug?
		beq 	t3, zero, waitPs # Wait if not pressed
		nop
waitRl:	# Wait for button release state
		lb 		t2, 0x0(t0) # Read byte from port
		and 	t3, t2, t1 # Apply bitmask
		bne 	t3, zero, waitRl # Wait if not released
		nop
		jr 		ra # Return	
		nop
.end wait