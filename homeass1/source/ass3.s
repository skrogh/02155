#include <iregdef.h>
.set noreorder
.text 
.globl start
.ent start

start:
		lui		t0, 0x0000		# load first half
		ori	s0, t0, 0x0001	# load second half
		lui		t0, 0x0000		# load first half
		ori	s1, t0, 0x0001	# load second half
		addu	s2, s0, s1		# add them addu,
		add		s2, s0, s1		# add them add

		lui		t0, 0x0000		# load first half
		ori	s0, t0, 0x0001	# load second half
		lui		t0, 0x7FFF		# load first half
		ori	s1, t0, 0xFFFF	# load second half
		addu	s2, s0, s1		# add them addu,
		add		s2, s0, s1		# add them add

		lui		t0, 0x0000		# load first half
		ori	s0, t0, 0x0001	# load second half
		lui		t0, 0xFFFF		# load first half
		ori	s1, t0, 0xFFFF	# load second half
		addu	s2, s0, s1		# add them addu,
		add		s2, s0, s1		# add them add

		lui		t0, 0x0000		# load first half
		ori	s0, t0, 0x0002	# load second half
		lui		t0, 0x0000		# load first half
		ori	s1, t0, 0x0001	# load second half
		subu	s2, s0, s1		# subtract them subu,
		sub		s2, s0, s1		# subtract them sub

		lui		t0, 0x0000		# load first half
		ori	s0, t0, 0x0000	# load second half
		lui		t0, 0x0000		# load first half
		ori	s1, t0, 0x0001	# load second half
		subu	s2, s0, s1		# subtract them subu,
		sub		s2, s0, s1		# subtract them sub

		lui		t0, 0x8000		# load first half
		ori	s0, t0, 0x0000	# load second half
		lui		t0, 0x0000		# load first half
		ori	s1, t0, 0x0001	# load second half
		subu	s2, s0, s1		# subtract them subu,
		sub		s2, s0, s1		# subtract them sub
.end start