start:	lui		s0, 0x1000
		addu	t0, zero, zero 
		addiu	s0, t0, 20
loop:	lw		t1, (s0)
		lw		t2, 4(s0)
		lw		t3, 8(s0)
		addu	t0, t0, t1 
		addu	t0, t0, t2 
		addiu	s0, s0, 12
		sltu	t5, t4, s0
		beq		t5, zero, loop
		addu	t0, t0, t3
end:
