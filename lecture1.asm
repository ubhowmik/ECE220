.ORIG x3000

;;Lecture1 Examples
; 1. initialize a register
        AND R1, R1, #0


; 2. copy from one register to another
        ADD R1, R1, #5
        ADD R2, R1, #0

; 3. compute 5 - 3
        AND R2, R2, #0
        ADD R2, R2, #3
        NOT R2, R2
        ADD R2, R2, #1
        ADD R3, R1, R2

; 4. compute 4 x 3
        LD R4, operand_1
        LD R5, operand_2
        AND R6, R6, #0
MULT_LOOP
        ADD R6, R4, R6
        ADD R5, R5, #-1
        BRp MULT_LOOP

        HALT

operand_1       .FILL x0004
operand_2       .FILL x0003

.END
