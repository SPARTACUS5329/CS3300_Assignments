.bss
ascii: .space 2
.data
t1: .asciz "This shouldn't print, if it does, you are cooked!!\n"
t3: .asciz "This should print first\n"
t11: .asciz "This should print third\n"
t28: .asciz "This should print fourth\n"
t38: .asciz "This should print fifth\n"
t56: .asciz "This should print last\n"
t74: .asciz "This should print second\n"
t92: .asciz "%s"
.text
.globl dead
dead:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
pushl $t1
call printf
addl $4, %esp

movl %eax, -8(%ebp)
movl $-1, %eax

leave
ret
.globl breaks
breaks:
pushl %ebp
movl %esp, %ebp
subl $36, %esp
pushl $t3
call printf
addl $4, %esp

movl %eax, -8(%ebp)
xorl %eax, %eax
movb $0, %al
movl %eax, -12(%ebp)
movl $19, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $0, %al
movl %eax, -20(%ebp)
movl $40, %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -20(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $0, %al
movl %eax, -28(%ebp)
movl $56, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl face
face:
pushl %ebp
movl %esp, %ebp
subl $68, %esp
pushl $t11
call printf
addl $4, %esp

movl %eax, -8(%ebp)
xorl %eax, %eax
movb $'=', %al
movl %eax, -12(%ebp)
movl $21, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal ascii, %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'=', %al
movl %eax, -20(%ebp)
movl $27, %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %eax
leal ascii, %ebx
movl -20(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'.', %al
movl %eax, -28(%ebp)
movl $24, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
leal ascii, %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'(', %al
movl %eax, -36(%ebp)
movl $20, %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
leal ascii, %ebx
movl -36(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'^', %al
movl %eax, -44(%ebp)
movl $22, %eax
movl %eax, -48(%ebp)
movl -48(%ebp), %eax
leal ascii, %ebx
movl -44(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'^', %al
movl %eax, -52(%ebp)
movl $26, %eax
movl %eax, -56(%ebp)
movl -56(%ebp), %eax
leal ascii, %ebx
movl -52(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $')', %al
movl %eax, -60(%ebp)
movl $28, %eax
movl %eax, -64(%ebp)
movl -64(%ebp), %eax
leal ascii, %ebx
movl -60(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl bubbleout
bubbleout:
pushl %ebp
movl %esp, %ebp
subl $52, %esp
movl $18, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
pushl $t28
call printf
addl $4, %esp

movl %eax, -16(%ebp)
.L1:
xorl %eax, %eax
movl -8(%ebp), %ecx
movl $13, %edx
cmpl %edx, %ecx
setge %al

movl %eax, -20(%ebp)
movl -20(%ebp), %ecx
cmpl $1, %ecx
je .L2
jmp .L3
.L2:
xorl %eax, %eax
movb $'_', %al
movl %eax, -24(%ebp)
movl -8(%ebp), %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
leal ascii, %ebx
movl -24(%ebp), %eax
movl %eax, (%ebx)
movl -8(%ebp), %eax
subl $1, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
movl %eax, -8(%ebp)
jmp .L1
.L3:
xorl %eax, %eax
movb $')', %al
movl %eax, -36(%ebp)
movl $54, %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
leal ascii, %ebx
movl -36(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'/', %al
movl %eax, -44(%ebp)
movl $55, %eax
movl %eax, -48(%ebp)
movl -48(%ebp), %eax
leal ascii, %ebx
movl -44(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl bubbletext
bubbletext:
pushl %ebp
movl %esp, %ebp
subl $76, %esp
pushl $t38
call printf
addl $4, %esp

movl %eax, -8(%ebp)
xorl %eax, %eax
movb $'!', %al
movl %eax, -12(%ebp)
movl $37, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal ascii, %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'e', %al
movl %eax, -20(%ebp)
movl $34, %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %eax
leal ascii, %ebx
movl -20(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'w', %al
movl %eax, -28(%ebp)
movl $36, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
leal ascii, %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'m', %al
movl %eax, -36(%ebp)
movl $33, %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
leal ascii, %ebx
movl -36(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'o', %al
movl %eax, -44(%ebp)
movl $35, %eax
movl %eax, -48(%ebp)
movl -48(%ebp), %eax
leal ascii, %ebx
movl -44(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $')', %al
movl %eax, -52(%ebp)
movl $39, %eax
movl %eax, -56(%ebp)
movl -56(%ebp), %eax
leal ascii, %ebx
movl -52(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'(', %al
movl %eax, -60(%ebp)
movl $32, %eax
movl %eax, -64(%ebp)
movl -64(%ebp), %eax
leal ascii, %ebx
movl -60(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'_', %al
movl %eax, -68(%ebp)
movl $38, %eax
movl %eax, -72(%ebp)
movl -72(%ebp), %eax
leal ascii, %ebx
movl -68(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl head
head:
pushl %ebp
movl %esp, %ebp
subl $76, %esp
pushl $t56
call printf
addl $4, %esp

movl %eax, -8(%ebp)
xorl %eax, %eax
movb $'/', %al
movl %eax, -12(%ebp)
movl $1, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $0, %al
movl %eax, -20(%ebp)
movl $2, %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -20(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'_', %al
movl %eax, -28(%ebp)
movl $3, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'_', %al
movl %eax, -36(%ebp)
movl $4, %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -36(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'/', %al
movl %eax, -44(%ebp)
movl $7, %eax
movl %eax, -48(%ebp)
movl -48(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -44(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $0, %al
movl %eax, -52(%ebp)
movl $8, %eax
movl %eax, -56(%ebp)
movl -56(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -52(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'_', %al
movl %eax, -60(%ebp)
movl $5, %eax
movl %eax, -64(%ebp)
movl -64(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -60(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'_', %al
movl %eax, -68(%ebp)
movl $6, %eax
movl %eax, -72(%ebp)
movl -72(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -68(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl paws
paws:
pushl %ebp
movl %esp, %ebp
subl $76, %esp
pushl $t74
call printf
addl $4, %esp

movl %eax, -8(%ebp)
xorl %eax, %eax
movb $'(', %al
movl %eax, -12(%ebp)
movl $42, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'(', %al
movl %eax, -20(%ebp)
movl $46, %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -20(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $')', %al
movl %eax, -28(%ebp)
movl $44, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $')', %al
movl %eax, -36(%ebp)
movl $48, %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -36(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'"', %al
movl %eax, -44(%ebp)
movl $43, %eax
movl %eax, -48(%ebp)
movl -48(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -44(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'"', %al
movl %eax, -52(%ebp)
movl $47, %eax
movl %eax, -56(%ebp)
movl -56(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -52(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'_', %al
movl %eax, -60(%ebp)
movl $49, %eax
movl %eax, -64(%ebp)
movl -64(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -60(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'/', %al
movl %eax, -68(%ebp)
movl $50, %eax
movl %eax, -72(%ebp)
movl -72(%ebp), %eax
leal 8(%ebp, %eax), %ebx
movl -68(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl print
print:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
leal 8(%ebp), %eax
movl %eax, -8(%ebp)
leal -8(%ebp), %eax
pushl %eax
pushl $t92
call printf
addl $8, %esp

movl %eax, -12(%ebp)
movl $0, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $120, %esp
movl $56, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
xorl %eax, %eax
movb $0, %al
movl %eax, -12(%ebp)
movl $57, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal ascii, %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
.L4:
xorl %eax, %eax
movl -8(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
setge %al

movl %eax, -20(%ebp)
movl -20(%ebp), %ecx
cmpl $1, %ecx
je .L5
jmp .L6
.L5:
xorl %eax, %eax
movb $' ', %al
movl %eax, -24(%ebp)
movl -8(%ebp), %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
leal ascii, %ebx
movl -24(%ebp), %eax
movl %eax, (%ebx)
movl -8(%ebp), %eax
subl $1, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
movl %eax, -8(%ebp)
jmp .L4
.L6:
leal ascii, %eax
movl %eax, -36(%ebp)
leal -36(%ebp), %eax
pushl %eax
call breaks
addl $4, %esp

movl %eax, -40(%ebp)
xorl %eax, %eax
movl -40(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
setg %al

movl %eax, -44(%ebp)
movl -44(%ebp), %ecx
cmpl $1, %ecx
je .L12
jmp .L11
.L12:
call dead
addl $0, %esp

movl %eax, -48(%ebp)
xorl %eax, %eax
movl -48(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -52(%ebp)
movl -52(%ebp), %ecx
cmpl $1, %ecx
je .L7
jmp .L11
.L11:
leal ascii, %eax
movl %eax, -56(%ebp)
leal -56(%ebp), %eax
pushl %eax
call paws
addl $4, %esp

movl %eax, -60(%ebp)
call face
addl $0, %esp

movl %eax, -64(%ebp)
xorl %eax, %eax
movl -60(%ebp), %ecx
movl -64(%ebp), %edx
cmpl %edx, %ecx
setne %al

movl %eax, -68(%ebp)
movl -68(%ebp), %ecx
cmpl $1, %ecx
je .L13
jmp .L10
.L13:
call dead
addl $0, %esp

movl %eax, -72(%ebp)
xorl %eax, %eax
movl -72(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -76(%ebp)
movl -76(%ebp), %ecx
cmpl $1, %ecx
je .L7
jmp .L10
.L10:
call bubbleout
addl $0, %esp

movl %eax, -80(%ebp)
call bubbletext
addl $0, %esp

movl %eax, -84(%ebp)
xorl %eax, %eax
movl -80(%ebp), %ecx
movl -84(%ebp), %edx
cmpl %edx, %ecx
sete %al

movl %eax, -88(%ebp)
movl -88(%ebp), %ecx
cmpl $1, %ecx
je .L14
jmp .L9
.L14:
leal ascii, %eax
movl %eax, -92(%ebp)
leal -92(%ebp), %eax
pushl %eax
call head
addl $4, %esp

movl %eax, -96(%ebp)
xorl %eax, %eax
movl -96(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -100(%ebp)
movl -100(%ebp), %ecx
cmpl $1, %ecx
je .L7
jmp .L9
.L9:
call dead
addl $0, %esp

movl %eax, -104(%ebp)
xorl %eax, %eax
movl -104(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -108(%ebp)
movl -108(%ebp), %ecx
cmpl $1, %ecx
je .L7
jmp .L8
.L7:
leal ascii, %eax
movl %eax, -112(%ebp)
leal -112(%ebp), %eax
pushl %eax
call print
addl $4, %esp

movl %eax, -116(%ebp)
.L8:
movl $0, %eax

leave
ret
