.data 
fmt1:   .asciz "Value at b is %d\n"
fmt2:   .asciz "Current Nesting: %d\n"
fmt3:   .asciz "Arg before is %d\n"
fmt4:   .asciz "Arg after is %d\n"
fmt5:   .asciz "Back to Nesting: %d\n"

    .text
    .globl b
b:  
    pushl   %ebp                # Prologue
    movl    %esp, %ebp

    movl    8(%ebp), %eax
    imull   %eax, %eax
    movl    %eax, 8(%ebp)

    pushl   8(%ebp)
    pushl   $fmt1
    call    printf
    addl    $8, %esp

    movl    $0, %eax
    leave
    ret

    .globl a
a:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $4, %esp

    pushl   12(%ebp)
    pushl   $fmt2
    call    printf
    addl    $8, %esp

    movl   8(%ebp), %eax
    movl   $1024, %ebx
    imull  %ebx, %ebx
    cmpl   %ebx, %eax
    jge     then_block
    jmp     else_block

then_block:
    jmp     end_a

else_block:
    pushl   8(%ebp)
    pushl   $fmt3
    call    printf
    addl    $8, %esp

    pushl   8(%ebp)
    call    b
    addl    $4, %esp

    movl    8(%ebp), %eax
    movl    $1024, %ebx
    imull   %ebx, %eax
    movl   %eax, 8(%ebp)

    pushl   8(%ebp)
    pushl   $fmt4
    call    printf
    addl    $8, %esp

    movl    12(%ebp), %eax
    addl    $1, %eax
    pushl   %eax
    movl    8(%ebp), %eax
    pushl   %eax
    call    a
    addl    $8, %esp

    pushl   12(%ebp)
    pushl   $fmt5
    call    printf
    addl    $8, %esp

end_a:
    movl    $0, %eax
    
    leave
    ret

    .globl main
main:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp

    movl    $1, %eax
    pushl   %eax
    movl    $100, %eax
    pushl   %eax
    call    a
    addl    $8, %esp

    movl    $0, %eax
    leave
    ret