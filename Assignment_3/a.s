.bss
.data
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $44, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movb $'A', %eax
movl %eax, -12(%ebp)
movl -8(%ebp), %eax
addl $5, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal -20(%ebp, %eax), %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
