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
.main:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movl $0, %eax

leave
ret
