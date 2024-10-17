.data
fmt1:   .asciz "Factorial of %d is %d\n"
fmt2:   .asciz "Global = %d\n"

.bss
global: .space 4

    .text
    .globl sideEffect

sideEffect:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    
    movl    global, %eax        # Load 'global' into EAX
    addl    $1, %eax            # Increment EAX by 1
    movl    %eax, global        # Store updated value in 'global'
    
    movl    $0, %eax            # Return 0

    leave                       # Epilogue
    ret                         # Return to caller


    .globl factorial
factorial:
    pushl  %ebp                # Prologue
    movl   %esp, %ebp
    subl   $4, %esp            # Allocate space for local 'res'
    
    movl   8(%ebp), %eax       # Move first arg 'x' into EAX
    cmpl   $0, %eax            # Compare 'x' with 0
    jne    else_block          # If x != 0, jump to else_block

    # Then-block
    movl   $1, -4(%ebp)        # res = 1

    jmp    end_factorial

else_block:
    # Else-block
    movl   8(%ebp), %eax       # Load 'x' into EAX
    subl   $1, %eax            # x = x - 1
    pushl  %eax                # Push 'x' as argument for recursive call
    call   factorial           # Call factorial(x-1)
    addl   $4, %esp            # Clean up the stack
    
    movl   8(%ebp), %ebx       # Load original 'x' into EBX
    imull  %eax, %ebx          # res = x * factorial(x-1)
    movl   %ebx, -4(%ebp)      # Store 'res' in local variable


end_factorial:
    movl   -4(%ebp), %eax      # Move 'res' to EAX for return

    leave                      # Epilogue
    ret                        # Return to caller

    .globl main
main:
    pushl  %ebp                # Prologue
    movl   %esp, %ebp
    subl   $4, %esp            # Allocate space for local 'n'

    movl   $10, -4(%ebp)       # n = 10
    movl   $0, global          # global = 0

loop_start:
    call   sideEffect          # Call sideEffect()

    movl   %eax, %ebx          # Move return value to EBX
    cmpl   $0, %ebx            # Compare return value with 0
    jg     then_block          # If return value > 0, jump to then_block

    movl   -4(%ebp), %eax      # Move 'n' into EAX
    cmpl   $0, %eax            # Compare 'n' with 0
    jge   then_block           # If n >= 0, jump to then_block
    jmp   else_block2         # Else, jump to else_block2

then_block:
    # Then-block
    pushl  -4(%ebp)            # Push 'n' as first arg
    pushl  %eax                # Push return value as second arg
    pushl  $fmt1               # Push address of fmt1
    call   printf              # Call printf
    addl   $12, %esp           # Clean up the stack

    pushl  global              # Push 'global' as second arg
    pushl  $fmt2               # Push address of fmt2
    call   printf              # Call printf
    addl   $8, %esp            # Clean up the stack

    movl   -4(%ebp), %eax      # Move 'n' into EAX
    subl   $1, %eax            # n = n - 1
    movl   %eax, -4(%ebp)      # Store updated 'n'

    jmp    loop_start          # Repeat the loop

else_block2:
    # Else-block
    movl   $0, %eax            # return 0
    leave                      # Epilogue
    ret                        # Return to caller