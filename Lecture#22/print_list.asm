    .ORIG x3000
MAIN
    LD R5, RSTACK
    LD R6, RSTACK

    LD R0, HEAD
    STR R0, R6, #0 ; push list head address to the stack

    JSR PRINT_LIST

    HALT

HEAD
    .FILL x2004
RSTACK
    .FILL x7000
PRINT_LIST
    ; Bookkeeping
    ADD R6, R6, #-3 ; Space for bookkeeping
    STR R7, R6, #1  ; Save return address
    STR R5, R6, #0  ; Save prev. frame pointer

    ADD R5, R6, #-1 ; Move frame pointer

    ; if (!head) return 0;
    LDR R1, R5, #4  ; R1 <- head
    BRz DONE        ; if head is NULL

    ; printf("%c", head->data);
    LDR R0, R5, #4
    LDR R0, R0, #0
    OUT

    ; print_list(head->next)
    LDR R1, R1, #1  ; R1 <- head->next
    ADD R6, R6, #-1 ; Push head->next as parameter
    STR R1, R6, #0

    JSR PRINT_LIST

    ; return
    LDR R0, R6, #0  ; Load return value to R0
    STR R0, R5, #3  ; Store return value from R0 to correct location

    ADD R6, R6, #2

    BR TEARDOWN

DONE
    AND R0, R0, #0
    STR R0, R5, #3

TEARDOWN

    LDR R7, R5, #2  ; Restore R7
    LDR R5, R5, #1  ; Restore R5

    ADD R6, R6, #2  ; Pop stack

    RET

    .END
