start:	lui		s0, 0x1000
		addu	t0, zero, zero 
		addiu	s0, t0, 20
loop:	lw		t1, (s0)
		addu	t0, t0, t1 #use after load hazard
		lw		t2, 4(s0)
		addu	t0, t0, t2 #use after load hazard
		lw		t3, 8(s0)
		addiu	s0, s0, 12
		addu	t0, t0, t3
		sltu	t5, t4, s0
		beq		t5, zero, loop
		nop
end:
