    AREA MyCode, CODE, READONLY  
                     
    ENTRY                        

    LDR R0, =0x40000000        
    LDR R0, [R0]               

    LDR R1, =0x40000004       
    LDR R1, [R1]               

    LDR R2, =0x40000008        
    LDR R2, [R2]               

sorting
    CMP R0, R1       
    BGT swap_0_1      

    CMP R1, R2       
    BGT swap_1_2      

    CMP R0, R1       
    BGT swap_0_1      

    B done            

swap_0_1
    MOV R3, R0       
    MOV R0, R1
    MOV R1, R3
    B sorting        

swap_1_2
    MOV R3, R1       
    MOV R1, R2
    MOV R2, R3
    B sorting        

done
    END               ; End of program

