	area mycode, code, readonly
enter
	ldr r0,=0x40000000
	ldr r0,[r0]
	
	mov r1,#0
	mov r2,#0
	mov r3,#32
	
COUNTER
	tst r0,#1
	addne r1,r1,#1
	addeq r2,r2,#1
	lsr r0,r0,#1
	subs r3,r3,#32
	bne COUNTER
	end