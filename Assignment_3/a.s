.bss
.data
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $30, %esp
xorl %eax, %eax
movb $'A', %al
movl %eax, -4(%ebp)
movl $0, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
leal -12(%ebp, %eax), %ebx
movl -4(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'B', %al
movl %eax, -22(%ebp)
movl $1, %eax
movl %eax, -26(%ebp)
movl -26(%ebp), %eax
leal -12(%ebp, %eax), %ebx
movl -22(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
