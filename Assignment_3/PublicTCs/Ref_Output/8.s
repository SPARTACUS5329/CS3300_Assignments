.data
fmt1:   .asciz "No printing\n"
fmt2:   .asciz "I love 3s\n"

    .text
    .globl main
main:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp
    subl    $4, %esp

    movl    $1, %eax
    movl    $0, %ebx
    cmpl    %ebx, %eax
    jle     else_block1

then_block1:
    movl    $2, %eax
    movl    $0, %ebx
    cmpl    %ebx, %eax
    jge     else_block2

then_block2:
    pushl   $fmt1
    call    printf
    addl    $4, %esp

else_block2:
    movl    $3, %eax
    movl    $0, %ebx
    cmpl    %ebx, %eax
    jle     else_block3

then_block3:
    movl    $0, %eax
    movl    $0, %ebx
    cmpl    %ebx, %eax
    jne     else_block4

then_block4:
    movl    $3, %eax
    movl    %eax, -4(%ebp)

loop_start:
    movl    -4(%ebp), %eax
    imull   %eax, %eax
    movl    $6561, %ebx
    cmpl    %ebx, %eax
    jle     then_block5
    jmp     loop_end

then_block5:
    pushl   $fmt2
    call    printf
    addl    $4, %esp

    movl    -4(%ebp), %eax
    movl    -4(%ebp), %ebx
    imull   %ebx, %eax
    movl    %eax, -4(%ebp)

    jmp     loop_start

loop_end:

else_block4:

else_block3:

else_block1:

    movl    $0, %eax             # return 0
    leave                        # Epilogue
    ret                          # Return to caller
