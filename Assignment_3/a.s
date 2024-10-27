.bss
b: .space 4
t1: .space 4
.data
.text
movl $2, %eax
movl %eax, t1
movl t1, %eax
movl %eax, b
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $20, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
xorl %eax, %eax
movl -8(%ebp), %ecx
movl $3, %edx
cmpl %ecx, %edx
sete %al

movl %eax, -12(%ebp)
movl -12(%ebp), %ecx
cmpl $1, %ecx
je .L1
jmp .L2
.L1:
movl $2, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
movl %eax, -8(%ebp)
.L2:
movl $0, %eax

leave
ret
