                  AREA MYCODE, CODE, READONLY
ENTRY;
START
		LDR R0, =0x40000000
		LDR R1, =0x40000004
		
		LDR R2, [R0]
		LDR R3, [R1]

		MOV R4, R2
		MOV R2, R3
		MOV R3, R4
		
		STR R2, [R0]
		STR R3, [R1]
		END
