.bss
.data
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $52, %esp
movl $1, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movb $'B', %eax
movl %eax, -12(%ebp)
movl $1, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
leal -20(%ebp, %eax), %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
movb $0, %eax
movl %eax, -44(%ebp)
movl -8(%ebp), %eax
addl $1, %eax
movl %eax, -48(%ebp)
movl -48(%ebp), %eax
leal -20(%ebp, %eax), %ebx
movl -44(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
