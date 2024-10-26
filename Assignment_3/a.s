.bss
.data
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $36, %esp
movb $'A', %eax
movl %eax, -4(%ebp)
movl $5, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
leal -12(%ebp, %eax), %ebx
movl -4(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
