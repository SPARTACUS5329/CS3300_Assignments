.data
msg1:   .asciz "x is less than y\n"
msg2:   .asciz "x is not less than y\n"

    .text
    .globl main
main:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $8, %esp            # Allocate space for 'x' and 'y'

    movl    $5, -4(%ebp)        # x = 5
    movl    $10, -8(%ebp)       # y = 10

    movl    -4(%ebp), %eax      # Move 'x' into EAX
    cmpl    -8(%ebp), %eax      # Compare 'x' with 'y'
    jge     else_block          # If x >= y, jump to else_block

    # Then-block
    pushl   $msg1               # Push address of msg1
    call    printf
    addl    $4, %esp             # Clean up the stack
    jmp     end_if

else_block:
    # Else-block
    pushl   $msg2               # Push address of msg2
    call    printf
    addl    $4, %esp             # Clean up the stack

end_if:
    movl    $0, %eax             # return 0
    leave                        # Epilogue
    ret                          # Return to caller