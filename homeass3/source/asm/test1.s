	.file	1 "test1.c"

 # -G value = 8, Cpu = 3000, ISA = 1
 # GNU C version cygnus-2.7.2-970404 (mips-mips-ecoff) compiled by GNU C version cygnus-2.7.2-970404.
 # options passed:  -msoft-float -O0 -Wall
 # options enabled:  -fpeephole -ffunction-cse -fkeep-static-consts
 # -fpcc-struct-return -fcommon -fverbose-asm -fgnu-linker -msoft-float
 # -meb -mcpu=3000

gcc2_compiled.:
__gnu_compiled_c:
	.rdata
	.align	2
$LC0:
	.ascii	"Sum = %d\n\000"
	.text
	.align	2
	.globl	main
	.ent	main
main:							#Lots of stuff going on in __start before this point
	.frame	$fp,8232,$31		# vars= 8208, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	subu	$sp,$sp,8232
	sw	$31,8228($sp)
	sw	$fp,8224($sp)
	move	$fp,$sp
	jal	__main
	jal	clear_cache		#start profiling
	sw	$0,8208($fp)	#sum in 8208. Set sum=0. Is miss (8208 + frame pointer, but everything is relative to frame pointer)
	sw	$0,8212($fp)	#i in 8212 (j in 8216). Set i=0. Is miss
$L2:	#init loop
	lw	$2,8212($fp)	#load i in $2 (will miss first time, hit the other 2047)
	slt	$3,$2,2048 		#check if i<2048
	bne	$3,$0,$L5 		#continue loop if i<2048
	j	$L3				#else exit loop
$L5:
	lw	$2,8212($fp)	#load i in $2 (again) will be a hit
	move	$3,$2		#copy i to $3
	sll	$2,$3,2			#$2 = i*4
	addu	$3,$fp,16	
	addu	$2,$2,$3	#$2 = i*4 + framepointer + 16; basically get the address for A[i]
	li	$3,1			# 0x00000001
	sw	$3,0($2)		#store 1 at A[i]. Is miss 1/4 if the time, hit 3/4
$L4:
	lw	$2,8212($fp)	#load i into $2 again (will hit)
	addu	$3,$2,1		#incriment i
	sw	$3,8212($fp)	#store i. (will hit)
	j	$L2				# repeat loop
$L3:
	.set	noreorder
	nop
	.set	reorder
	sw	$0,8212($fp)	#set i=0 (will hit)
$L6:	#data manupulation, outer loop
	lw	$2,8212($fp)	#load i into $2 (will hit)
	slt	$3,$2,1920		#check if i<1920 (tab_size-cache_size)
	bne	$3,$0,$L9		#continue loop if it is so.
	j	$L7				#else exit
$L9:	
	sw	$0,8216($fp)	#set j=0 (will mostly hit)
$L10:	#data manipualtion, inner loop
	lw	$2,8216($fp)	#load j into $2 (will hit)
	slt	$3,$2,5			#check if j<5
	bne	$3,$0,$L13		#continue loop if it is so.
	j	$L8				#else exit
$L13:	#actual datamanipulation
	lw	$2,8212($fp)	#load i into $2 (most likely hit)
	move	$3,$2		#find address for A[i]
	sll	$2,$3,2			
	addu	$3,$fp,16
	addu	$2,$2,$3
	lw	$3,8208($fp)	#load sum in $3 (will hit)
	lw	$2,0($2)		#load A[i] in $2 (most likely miss)
	addu	$3,$3,$2	#add A[i] to sum
	sw	$3,8208($fp)	#store sum (mostly hits)
	lw	$2,8212($fp)	#load i (most likely hit)
	move	$3,$2		#get address for A[i + CACHE_SIZE]
	sll	$2,$3,2
	addu	$3,$fp,16
	addu	$2,$2,$3
	addu	$3,$2,512
	lw	$2,8208($fp)	#load A[i + CACHE_SIZE] in $2 (will be miss)
	lw	$3,0($3)		#load sum in $3 (most likely hit)
	addu	$2,$2,$3	#add A[i + ...] to sum
	sw	$2,8208($fp)	#store sum (mostly hits)
$L12:
	lw	$2,8216($fp)	#load j in $2 (most likely hit)
	addu	$3,$2,1		#incriment
	sw	$3,8216($fp)	#store j (hits)
	j	$L10			#continue inner loop
$L11:
$L8:
	lw	$2,8212($fp)	#load i in $2 (will hit)
	addu	$3,$2,1		#incriment
	sw	$3,8212($fp)	#store i (hits)
	j	$L6					#continue outer loop
$L7:
	jal	promexit		#stop counting miss and hit
	la	$4,$LC0
	lw	$5,8208($fp)
	jal	printf
	move	$2,$0
	j	$L1
$L1:
	move	$sp,$fp		# sp not trusted here
	lw	$31,8228($sp)
	lw	$fp,8224($sp)
	addu	$sp,$sp,8232
	j	$31
	.end	main
