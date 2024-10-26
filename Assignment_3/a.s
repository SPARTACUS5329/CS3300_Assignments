.bss
.data
t13: .asciz "%s"
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $82, %esp
movl $1, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
xorl %eax, %eax
cmpl -8(%ebp), $4
setl %al

movl %eax, -12(%ebp)
cmpl -12(%ebp), $1
je .L1
jmp .L2
L1:
movb $'B', %eax
movl %eax, -16(%ebp)
movl $0, %eax
movl %eax, -20(%ebp)
movl -20(%ebp), %eax
leal -24(%ebp, %eax), %ebx
movl -16(%ebp), %eax
movl %eax, (%ebx)
movb $'B', %eax
movl %eax, -38(%ebp)
movl $1, %eax
movl %eax, -42(%ebp)
movl -42(%ebp), %eax
leal -24(%ebp, %eax), %ebx
movl -38(%ebp), %eax
movl %eax, (%ebx)
jmp .L3
L2:
movb $'C', %eax
movl %eax, -46(%ebp)
movl $0, %eax
movl %eax, -50(%ebp)
movl -50(%ebp), %eax
leal -24(%ebp, %eax), %ebx
movl -46(%ebp), %eax
movl %eax, (%ebx)
movb $'C', %eax
movl %eax, -54(%ebp)
movl $1, %eax
movl %eax, -58(%ebp)
movl -58(%ebp), %eax
leal -24(%ebp, %eax), %ebx
movl -54(%ebp), %eax
movl %eax, (%ebx)
L3:
movb $0, %eax
movl %eax, -62(%ebp)
movl -8(%ebp), %eax
addl $1, %eax
movl %eax, -66(%ebp)
movl -66(%ebp), %eax
leal -24(%ebp, %eax), %ebx
movl -62(%ebp), %eax
movl %eax, (%ebx)
movl -24(%ebp), %eax
movl %eax, -74(%ebp)
pushl -74(%ebp)
pushl $t13
call printf
addl $8, %esp

movl %eax, -78(%ebp)
movl $0, %eax

leave
ret
