/*
// MiniC program for complex boolean expressions
#include<stdio.h>

int dead()
{
    printf("This shouldn't print, if it does, you are cooked!!\n");
    return -1;
}

int main()
{
    if( !((((-1 == -1) || (dead() == 1)) && ((-1 == -1*-1) && (1/0 == 1))) && (dead() == 1)) )
    {
        printf("Hello\n");
    }
    return 0;
}
*/

    .data
fmt1:  .asciz "This shouldn't print, if it does, you are cooked!!\n"
fmt2: .asciz "Hello\n"

    .text
    .globl dead
dead:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp

    # Print "This shouldn't print, if it does, you are cooked!!"
    pushl   $fmt1               # Push fmt_dead to printf
    call    printf              # Call printf
    addl    $4, %esp            # Clean up stack

    movl    $-1, %eax           # Return -1 from dead()
    leave                       # Epilogue
    ret                         # Return to caller

    .globl main
main:
    pushl   %ebp                # Prologue
    movl    %esp, %ebp

    # if( !((((-1 == -1) || (dead() == 1)) && ((-1 == -1*-1) && (1/0 == 1))) && (dead() == 1)) )
    movl    $-1, %eax           # -1 == -1
    movl    $-1, %ebx
    cmpl    %ebx, %eax
    je      or_true

    call    dead                # dead() == 1
    movl    $1, %eax
    cmpl    $1, %eax
    je      or_true

or_true:
    movl    $-1, %eax           # -1 == -1
    movl    $-1, %ebx
    imull   %ebx, %eax
    movl    $-1, %ebx
    cmpl    %ebx, %eax
    jne      and1_false

    movl    $1, %eax            # 1/0 == 1
    movl    $0, %ebx
    idivl   %ebx
    movl    $1, %ebx
    cmpl    %ebx, %eax
    je      and1_true
    jmp     and1_false

and1_true:
    call    dead                # dead() == 1
    movl    $1, %eax
    cmpl    $1, %eax
    je      and2_true
    jmp     and2_false

and1_false:

and2_false:
    jmp     then_block

and2_true:
    jmp     else_block

then_block:
    pushl   $fmt2
    call    printf
    addl    $4, %esp

else_block:
    movl    $0, %eax
    leave
    ret