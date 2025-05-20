        AREA    Program, CODE, READwrite
        ENTRY

Main
        LDR     R1, =Value       
        LDR     R1, [R1]         
        LDR     R2, =Mask        
        LDRH    R2, [R2]         
        MOV     R3, R1, LSR #4    
        MOV     R3, R3, LSL #8   
        AND     R1, R1, R2       
        ADD     R1, R1, R3       
        LDR     R0, =Result      
        STR     R1, [R0]         
        SWI     0x11             

        ; Data section
        AREA    MyData, DATA, READWRITE
Value   DCB     0xFB             
        ALIGN                  

Mask    DCW     0x800F           
        ALIGN                   

Result  DCD     0               

        END
