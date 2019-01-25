.ORIG X3000
;ITEM1 X18
;ITEM2 X31
;ITEM3 X5
;MAIN PROGRAM:
	LD R6,STACK_START   ;LOAD R6 WITH STACK_START
	LD R0,ITEM1		    ;load the ITEM1 into R0
	JSR PUSH
	LD R0,ITEM2		    ;load the ITEM2 into R0
	JSR PUSH
	LD R0,ITEM3		    ;load the ITEM3 into R0
	JSR PUSH
	JSR POP				;POP ITEM3 INTO R0

    HALT
	
; Subroutines for carrying out the PUSH and POP functions.  This 
; program works with a stack consisting of memory locations x3FFF
; (BASE) through x3FFB (MAX).  R6 is the stack pointer.
;
POP            ST      R2,Save2       ; are needed by POP.
               ST      R1,Save1
               LD      R1,BASE        ; BASE contains -x3FFF.
               ADD     R1,R1,#-1      ; R1 contains -x4000.
               ADD     R2,R6,R1       ; Compare stack pointer to x4000
               BRz     fail_exit      ; Branch if stack is empty.
               LDR     R0,R6,#0       ; The actual "pop."
               ADD     R6,R6,#1       ; Adjust stack pointer
               BRnzp   success_exit
PUSH           ST      R2,Save2       ; Save registers that 
               ST      R1,Save1       ; are needed by PUSH.
               LD      R1,MAX         ; MAX contains -x3FFB
               ADD     R2,R6,R1       ; Compare stack pointer to -x3FFB
               BRz     fail_exit      ; Branch if stack is full.
               ADD     R6,R6,#-1      ; Adjust stack pointer
               STR     R0,R6,#0       ; The actual "push"
success_exit   LD      R1,Save1       ; Restore original 
               LD      R2,Save2       ; register values.
               AND     R5,R5,#0       ; R5 <-- success.
               RET
fail_exit      LD      R1,Save1       ; Restore original
               LD      R2,Save2       ; register values.
               AND     R5,R5,#0      
               ADD     R5,R5,#1       ; R5 <-- failure. 
               RET

; BASE contains -x3FFF.
BASE           .FILL   xC001 
MAX            .FILL   xC005
Save1          .FILL   x0000
Save2          .FILL   x0000

ITEM1    	   .FILL   x18 ;Values to be pushed into the stack
ITEM2		   .FILL   x31 		
ITEM3          .FILL   x5
STACK_START    .FILL   x4000
.END
