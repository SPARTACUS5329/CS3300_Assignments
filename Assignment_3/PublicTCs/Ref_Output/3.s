.data
fmt:    .asciz "i = %d\n"

    .text
    .globl main
main:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $4, %esp            # Allocate space for 'i'

    movl    $0, -4(%ebp)        # i = 0

loop_start:
    movl    -4(%ebp), %eax      # Move 'i' into EAX
    cmpl    $5, %eax            # Compare 'i' with 5
    jge     loop_end            # If i >= 5, exit loop

    pushl   -4(%ebp)            # Push 'i' as arg
    pushl   $fmt                # Push address of fmt
    call    printf              # Call printf
    addl    $8, %esp             # Clean up the stack

    movl    -4(%ebp), %eax      # Move 'i' into EAX
    addl    $1, %eax            # i = i + 1
    movl    %eax, -4(%ebp)      # Store updated 'i'

    jmp     loop_start          # Repeat the loop

loop_end:
    movl    $0, %eax             # return 0
    leave                        # Epilogue
    ret                          # Return to caller