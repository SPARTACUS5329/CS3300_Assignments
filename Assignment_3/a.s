.bss
glob_1: .space 4
glob_2: .space 4
yes_no: .space 2
.data
t1: .asciz "This is a zero\n"
t3: .asciz "This is a one\n"
t15: .asciz "%s"
t19: .asciz "\n"
t28: .asciz "%s"
t32: .asciz "\n"
t51: .asciz "g = %d\n"
t69: .asciz "%d\n"
t93: .asciz "Yes\n"
t101: .asciz "No\n"
t113: .asciz "Value = %d\n"
.text
.globl zero
zero:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
pushl $t1
call printf
addl $4, %esp

movl %eax, -8(%ebp)
movl $0, %eax

leave
ret
.globl one
one:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
pushl -96(%ebp)
call printf
addl $4, %esp

movl %eax, -8(%ebp)
movl $0, %eax

leave
ret
.globl add
add:
pushl %ebp
movl %esp, %ebp
subl $20, %esp
movl 8(%ebp), %eax
addl 12(%ebp), %eax
movl %eax, -4(%ebp)
movl 16(%ebp), %eax
addl 20(%ebp), %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
addl 24(%ebp), %eax
movl %eax, -12(%ebp)
movl -4(%ebp), %eax
addl -12(%ebp), %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax

leave
ret
.globl print_yes
print_yes:
pushl %ebp
movl %esp, %ebp
subl $66, %esp
movb $0, %eax
movl %eax, -4(%ebp)
movl $1, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
leal -12(%ebp, %eax), %ebx
movl -4(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax
movl %eax, -18(%ebp)
movl -18(%ebp), %eax
movl %eax, -22(%ebp)
.L1:
xorl %eax, %eax
movl -22(%ebp), %ecx
movl $6, %edx
cmpl %edx, %ecx
setl %al

movl %eax, -26(%ebp)
movl -26(%ebp), %ecx
cmpl $1, %ecx
je .L2
jmp .L3
.L2:
leal yes_no, %eax
movl %eax, -30(%ebp)
movl $0, %eax
movl %eax, -34(%ebp)
movl -34(%ebp), %eax
leal -12(%ebp, %eax), %ebx
leal -30(%ebp), %eax
movl %eax, (%ebx)
leal -12(%ebp), %eax
movl %eax, -42(%ebp)
pushl -42(%ebp)
pushl $t15
call printf
addl $8, %esp

movl %eax, -46(%ebp)
movl -22(%ebp), %eax
addl $2, %eax
movl %eax, -50(%ebp)
movl -50(%ebp), %eax
movl %eax, -22(%ebp)
jmp .L1
.L3:
pushl $t19
call printf
addl $4, %esp

movl %eax, -58(%ebp)
call zero
addl $0, %esp

movl %eax, -62(%ebp)
movl -62(%ebp), %eax

leave
ret
.globl print_no
print_no:
pushl %ebp
movl %esp, %ebp
subl $70, %esp
movb $0, %eax
movl %eax, -4(%ebp)
movl $1, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
leal -12(%ebp, %eax), %ebx
movl -4(%ebp), %eax
movl %eax, (%ebx)
movl $1, %eax
movl %eax, -18(%ebp)
movl -18(%ebp), %eax
movl %eax, -22(%ebp)
.L4:
xorl %eax, %eax
movl -22(%ebp), %ecx
movl $6, %edx
cmpl %edx, %ecx
setl %al

movl %eax, -26(%ebp)
movl -26(%ebp), %ecx
cmpl $1, %ecx
je .L5
jmp .L6
.L5:
leal yes_no, %eax
movl %eax, -30(%ebp)
movl $0, %eax
movl %eax, -34(%ebp)
movl -34(%ebp), %eax
leal -12(%ebp, %eax), %ebx
leal -30(%ebp), %eax
movl %eax, (%ebx)
leal -12(%ebp), %eax
movl %eax, -42(%ebp)
pushl -42(%ebp)
pushl $t28
call printf
addl $8, %esp

movl %eax, -46(%ebp)
movl -22(%ebp), %eax
addl $2, %eax
movl %eax, -50(%ebp)
movl -50(%ebp), %eax
movl %eax, -22(%ebp)
jmp .L4
.L6:
pushl $t32
call printf
addl $4, %esp

movl %eax, -58(%ebp)
call zero
addl $0, %esp

movl %eax, -62(%ebp)
movl -62(%ebp), %eax
addl $1, %eax
movl %eax, -66(%ebp)
movl -66(%ebp), %eax

leave
ret
.globl fibonacci
fibonacci:
pushl %ebp
movl %esp, %ebp
subl $44, %esp
xorl %eax, %eax
movl 8(%ebp), %ecx
movl $2, %edx
cmpl %edx, %ecx
setle %al

movl %eax, -4(%ebp)
movl -4(%ebp), %ecx
cmpl $1, %ecx
je .L7
jmp .L8
.L7:
movl 8(%ebp), %eax
subl $1, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
movl %eax, -12(%ebp)
jmp .L9
.L8:
movl 8(%ebp), %eax
subl $1, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
movl %eax, -20(%ebp)
pushl -20(%ebp)
call fibonacci
addl $4, %esp

movl %eax, -24(%ebp)
movl 8(%ebp), %eax
subl $2, %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
movl %eax, -32(%ebp)
pushl -32(%ebp)
call fibonacci
addl $4, %esp

movl %eax, -36(%ebp)
movl -24(%ebp), %eax
addl -36(%ebp), %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
movl %eax, -12(%ebp)
.L9:
movl -12(%ebp), %eax

leave
ret
.globl mess_around
mess_around:
pushl %ebp
movl %esp, %ebp
subl $52, %esp
movl 8(%ebp), %eax
addl 16(%ebp), %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
imull 20(%ebp), %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
movl %eax, -12(%ebp)
movl -12(%ebp), %eax
subl 20(%ebp), %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
xorl %edx, %edx
movl 8(%ebp), %ebx
idivl %ebx
movl %eax, -20(%ebp)
movl 8(%ebp), %eax
addl 16(%ebp), %eax
movl %eax, -24(%ebp)
movl -20(%ebp), %eax
imull -24(%ebp), %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
movl %eax, -40(%ebp)
pushl -40(%ebp)
pushl $t51
call printf
addl $8, %esp

movl %eax, -44(%ebp)
movl -12(%ebp), %eax
addl -32(%ebp), %eax
movl %eax, -48(%ebp)
movl -48(%ebp), %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $248, %esp
movl $1, %eax
movl %eax, -58(%ebp)
movl -58(%ebp), %eax
movl %eax, -4(%ebp)
movl $10, %eax
movl %eax, -62(%ebp)
movl -62(%ebp), %eax
movl %eax, -8(%ebp)
movb $'Y', %eax
movl %eax, -12(%ebp)
movl $6, %eax
movl %eax, -16(%ebp)
movl -52(%ebp), %eax
leal yes_no, %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
movb $'N', %eax
movl %eax, -20(%ebp)
movl $0, %eax
movl %eax, -24(%ebp)
movl -52(%ebp), %eax
leal yes_no, %ebx
movl -20(%ebp), %eax
movl %eax, (%ebx)
movb $'E', %eax
movl %eax, -28(%ebp)
movl $0, %eax
movl %eax, -32(%ebp)
movl -52(%ebp), %eax
leal yes_no, %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
movb $'O', %eax
movl %eax, -36(%ebp)
movl $0, %eax
movl %eax, -40(%ebp)
movl -52(%ebp), %eax
leal yes_no, %ebx
movl -36(%ebp), %eax
movl %eax, (%ebx)
movb $'S', %eax
movl %eax, -44(%ebp)
movl $0, %eax
movl %eax, -12(%ebp)
movl -52(%ebp), %eax
leal yes_no, %ebx
movl -44(%ebp), %eax
movl %eax, (%ebx)
movb $0, %eax
movl %eax, -48(%ebp)
movl $0, %eax
movl %eax, -52(%ebp)
movl -52(%ebp), %eax
leal yes_no, %ebx
movl -48(%ebp), %eax
movl %eax, (%ebx)
movl $10, %eax
movl %eax, -60(%ebp)
pushl -60(%ebp)
call fibonacci
addl $4, %esp

movl %eax, -64(%ebp)
movl -64(%ebp), %eax
movl %eax, -68(%ebp)
pushl -68(%ebp)
pushl $t69
call printf
addl $8, %esp

movl %eax, -72(%ebp)
movl $10, %eax
movl %eax, -76(%ebp)
leal yes_no, %eax
movl %eax, -80(%ebp)
movl $10, %eax
movl %eax, -84(%ebp)
movl $2, %eax
movl %eax, -88(%ebp)
leal yes_no, %eax
movl %eax, -92(%ebp)
pushl -92(%ebp)
pushl -88(%ebp)
pushl -84(%ebp)
pushl -80(%ebp)
pushl -76(%ebp)
call mess_around
addl $20, %esp

movl %eax, -96(%ebp)
.L10:
xorl %eax, %eax
movl -8(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
setg %al

movl %eax, -100(%ebp)
movl -100(%ebp), %ecx
cmpl $1, %ecx
je .L13
jmp .L12
.L13:
xorl %eax, %eax
movl -4(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -104(%ebp)
movl -104(%ebp), %ecx
cmpl $1, %ecx
je .L11
jmp .L12
.L11:
movl -8(%ebp), %eax
xorl %edx, %edx
movl $2, %ebx
idivl %ebx
movl %eax, -108(%ebp)
movl -108(%ebp), %eax
movl %eax, -112(%ebp)
movl -112(%ebp), %eax
imull $2, %eax
movl %eax, -116(%ebp)
xorl %eax, %eax
movl -116(%ebp), %ecx
movl -8(%ebp), %edx
cmpl %edx, %ecx
sete %al

movl %eax, -120(%ebp)
movl -120(%ebp), %ecx
cmpl $1, %ecx
je .L14
jmp .L16
.L16:
call zero
addl $0, %esp

movl %eax, -124(%ebp)
xorl %eax, %eax
movl -124(%ebp), %ecx
movl $0, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -128(%ebp)
movl -128(%ebp), %ecx
cmpl $1, %ecx
je .L18
jmp .L19
.L69680018:
.L17:
call print_no
addl $0, %esp

movl %eax, -132(%ebp)
call zero
addl $0, %esp

movl %eax, -136(%ebp)
xorl %eax, %eax
movl -132(%ebp), %ecx
movl -136(%ebp), %edx
cmpl %edx, %ecx
sete %al

movl %eax, -140(%ebp)
movl -140(%ebp), %ecx
cmpl $1, %ecx
je .L21
jmp .L22
.L0:
.L20:
call print_yes
addl $0, %esp

movl %eax, -144(%ebp)
call zero
addl $0, %esp

movl %eax, -148(%ebp)
xorl %eax, %eax
movl -144(%ebp), %ecx
movl -148(%ebp), %edx
cmpl %edx, %ecx
sete %al

movl %eax, -152(%ebp)
movl -152(%ebp), %ecx
cmpl $1, %ecx
je .L23
jmp .L24
.L69680018:
.L14:
pushl $t93
call printf
addl $4, %esp

movl %eax, -160(%ebp)
jmp .L25
.L15:
xorl %eax, %eax
movl $1, %ecx
movl $2, %edx
cmpl %edx, %ecx
setge %al

movl %eax, -164(%ebp)
movl -164(%ebp), %ecx
cmpl $1, %ecx
je .L26
jmp .L32
.L32:
xorl %eax, %eax
movl $2, %ecx
movl $1, %edx
cmpl %edx, %ecx
setle %al

movl %eax, -168(%ebp)
movl -168(%ebp), %ecx
cmpl $1, %ecx
je .L26
jmp .L31
.L31:
xorl %eax, %eax
movl $1, %ecx
movl $2, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -172(%ebp)
movl -172(%ebp), %ecx
cmpl $1, %ecx
je .L26
jmp .L30
.L30:
xorl %eax, %eax
movl $1, %ecx
movl $2, %edx
cmpl %edx, %ecx
setg %al

movl %eax, -176(%ebp)
movl -176(%ebp), %ecx
cmpl $1, %ecx
je .L26
jmp .L29
.L29:
xorl %eax, %eax
movl $1, %ecx
movl $1, %edx
cmpl %edx, %ecx
setne %al

movl %eax, -180(%ebp)
movl -180(%ebp), %ecx
cmpl $1, %ecx
je .L26
jmp .L28
.L28:
xorl %eax, %eax
movl $1, %ecx
movl $2, %edx
cmpl %edx, %ecx
setl %al

movl %eax, -184(%ebp)
movl -184(%ebp), %ecx
cmpl $1, %ecx
je .L26
jmp .L27
.L26:
pushl $t101
call printf
addl $4, %esp

movl %eax, -192(%ebp)
.L27:
.L25:
movl -8(%ebp), %eax
subl $1, %eax
movl %eax, -196(%ebp)
movl -196(%ebp), %eax
movl %eax, -8(%ebp)
jmp .L10
.L12:
call zero
addl $0, %esp

movl %eax, -200(%ebp)
call one
addl $0, %esp

movl %eax, -204(%ebp)
movl -200(%ebp), %eax
addl -204(%ebp), %eax
movl %eax, -208(%ebp)
call one
addl $0, %esp

movl %eax, -212(%ebp)
call zero
addl $0, %esp

movl %eax, -216(%ebp)
movl -212(%ebp), %eax
addl -216(%ebp), %eax
movl %eax, -220(%ebp)
call one
addl $0, %esp

movl %eax, -224(%ebp)
movl -220(%ebp), %eax
addl -224(%ebp), %eax
movl %eax, -228(%ebp)
movl -208(%ebp), %eax
addl -228(%ebp), %eax
movl %eax, -232(%ebp)
movl -232(%ebp), %eax
movl %eax, -112(%ebp)
movl -112(%ebp), %eax
movl %eax, -240(%ebp)
pushl -240(%ebp)
pushl $t113
call printf
addl $8, %esp

movl %eax, -244(%ebp)
movl $0, %eax

leave
ret
