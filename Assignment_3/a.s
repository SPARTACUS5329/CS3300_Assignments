.bss
.data
t1: .asciz "This shouldn't print, if it does, you are cooked!!\n"
t12: .asciz "Hello\n"
t14: .asciz "Hello\n"
.text
.globl dead
.dead:
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
.globl main
.main:
pushl %ebp
movl %esp, %ebp
subl $52, %esp
xorl %eax, %eax
movl $-1, %ecx
cmpl %ecx, $-1
sete %al

movl %eax, -4(%ebp)
movl -4(%ebp), %ecx
cmpl %ecx, $1
je .L4
jmp .L5
.L5:
call dead
addl $0, %esp

movl %eax, -8(%ebp)
xorl %eax, %eax
movl -8(%ebp), %ecx
cmpl %ecx, $1
sete %al

movl %eax, -12(%ebp)
movl -12(%ebp), %ecx
cmpl %ecx, $1
je .L4
jmp .L1
.L4:
movl $-1, %eax
imull $-1, %eax
movl %eax, -16(%ebp)
xorl %eax, %eax
movl $-1, %ecx
cmpl %ecx, -16(%ebp)
sete %al

movl %eax, -20(%ebp)
movl -20(%ebp), %ecx
cmpl %ecx, $1
je .L6
jmp .L1
.L6:
movl $1, %eax
idivl $0, %eax
movl %eax, -24(%ebp)
xorl %eax, %eax
movl -24(%ebp), %ecx
cmpl %ecx, $1
sete %al

movl %eax, -28(%ebp)
movl -28(%ebp), %ecx
cmpl %ecx, $1
je .L3
jmp .L1
.L3:
call dead
addl $0, %esp

movl %eax, -32(%ebp)
xorl %eax, %eax
movl -32(%ebp), %ecx
cmpl %ecx, $1
sete %al

movl %eax, -36(%ebp)
movl -36(%ebp), %ecx
cmpl %ecx, $1
je .L2
jmp .L1
.L2:
pushl $t12
call printf
addl $4, %esp

movl %eax, -44(%ebp)
.L1:
pushl $t14
call printf
addl $4, %esp

movl %eax, 12(%ebp)
.L2:
movl $0, %eax

leave
ret
