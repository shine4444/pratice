.text
.global _start
_start:
	bl 	DIS_WATCHDOG
	bl 	mem_ini
	bl 	copy_code_to_sdram
	ldr 	pc,=0x30000000
	ldr 	sp,=0x34000000
	bl 	main
loop:	
	b  	loop

DIS_WATCHDOG:
	ldr 	r0,=0x53000000
	mov 	r1,#0x00008000
	str 	r1,[r0]
	mov 	pc,lr
	
copy_code_to_sdram:
	mov	r0,#4096
	mov	r1,#0
	ldr	r2,=0x30000000
1:
	ldr	r3,[r1],#4
	str	r3,[r2],#4
	cmp	r1,r0
	bne	1b
	mov	pc,lr

mem_ini:
	ldr 	r0,=0x48000000
	add 	r1,r0,#52 
	adrl 	r2,mem_val
1:
	ldr	r3,[r2],#4
	str	r3,[r0],#4
	cmp	r1,r0
	bne	1b
	mov	pc,lr

.align 4
mem_val:
	.long	0x22011110
	.long	0x00000700
	.long	0x00000700
	.long	0x00000700
	.long	0x00000700
	.long	0x00000700
	.long	0x00000700
	.long	0x00018005
	.long	0x00018005
	.long	0x008c07a3
	.long	0x00000081
	.long	0x00000030
	.long	0x00000030	
