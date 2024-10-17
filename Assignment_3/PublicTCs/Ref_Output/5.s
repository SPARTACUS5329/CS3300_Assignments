.data
fmt:    .asciz "Maximum is %d\n"

    .text
    .globl max
max:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $8, %esp            # Allocate space for locals

    movl    8(%ebp), %eax       # Move first arg 'a' into EAX
    movl    12(%ebp), %ebx      # Move second arg 'b' into EBX
    cmpl    %ebx, %eax          # Compare 'a' with 'b'
    jle     else_block          # If a <= b, jump to else_block

    # Then-block: return a
    movl    %eax, -4(%ebp)      # Store 'a' in local variable
    movl    -4(%ebp), %eax      # Move 'a' to EAX for return
    jmp     end_max

else_block:
    # Else-block: return b
    movl    %ebx, -4(%ebp)      # Store 'b' in local variable
    movl    -4(%ebp), %eax      # Move 'b' to EAX for return

end_max:
    leave                       # Epilogue
    ret                         # Return to caller

    .globl main
main:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $12, %esp           # Allocate space locals

    movl    $15, -4(%ebp)        # num1 = 15
    movl    $25, -8(%ebp)        # num2 = 25

    movl    -4(%ebp), %eax      # Move 'num1' into EAX
    pushl   %eax                # Push 'num1' as first arg
    movl    -8(%ebp), %eax      # Move 'num2' into EAX
    pushl   %eax                # Push 'num2' as second arg
    call    max                  # Call function 'max'
    addl    $8, %esp             # Clean up the stack
    movl    %eax, -12(%ebp)      # maximum = max(num1, num2)

    pushl   -12(%ebp)            # Push 'maximum' as second arg
    pushl   $fmt                 # Push address of fmt as first arg
    call    printf               # Call printf
    addl    $8, %esp             # Clean up the stack

    movl    $0, %eax             # return 0
    leave                        # Epilogue
    ret                          # Return to caller