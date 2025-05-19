           AREA MYCODE,CODE,READONLY
ENTRY
START
     LDR R0,=0XFCA67590
	 MOV R1,#0
	 MOV R2,#0
	 MOV R3,#32
	
	
COUNTER
      LSRS R0,R0,#1
	  ADC R1,R1,#0
	  ADDCC R2,R2,#1
	  SUBS R3,R3,#1
	  BNE COUNTER

	  
	  
S B S
    NOP 
    END