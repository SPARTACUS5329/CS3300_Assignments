.data
fmt:    .asciz "Sum is %d\n"

    .text
    .globl add
add:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $4, %esp            # Allocate space for local 'result'

    movl    8(%ebp), %eax       # Move first arg 'a' into EAX
    movl    12(%ebp), %ebx      # Move second arg 'b' into EBX
    addl    %ebx, %eax          # result = a + b

    movl    %eax, -4(%ebp)      # Store 'result' in local variable
    movl    -4(%ebp), %eax      # Move 'result' to EAX for return

    leave                       # Epilogue
    ret                         # Return to caller

    .globl main
main:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $12, %esp           # Allocate space for locals
    movl    $5, -4(%ebp)        # x = 5
    movl    $10, -8(%ebp)       # y = 10
    
    movl    -4(%ebp), %eax      # Move 'x' into EAX
    pushl   %eax                # Push 'x' as arg
    movl    -8(%ebp), %eax      # Move 'y' into EAX
    pushl   %eax                # Push 'y' as arg
    
    call    add                  # Call add(x, y)
    addl    $8, %esp             # Clean up the stack 
    movl    %eax, -12(%ebp)      # sum = add(x, y)
    pushl   -12(%ebp)            # Push 'sum' as second arg 
    pushl   $fmt                 # Push address of format string
    call    printf               # Call printf
    
    addl    $8, %esp             # Clean up the stack
    movl    $0, %eax             # return 0
    leave                        # Epilogue
    ret                          # Return to caller