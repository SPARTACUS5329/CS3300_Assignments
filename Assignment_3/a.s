.bss
ascii: .space 10
.data
.text
.globl foo
foo:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
xorl %eax, %eax
movb $'A', %al
movl %eax, -4(%ebp)
movl $0, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
movl 8(%ebp), %edx
leal (%edx, %eax, 1), %ebx
movl -4(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $42, %esp
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
movb $'A', %al
movl %eax, -26(%ebp)
movl $1, %eax
movl %eax, -30(%ebp)
movl -30(%ebp), %eax
leal ascii(, %eax, 1), %ebx
movl -26(%ebp), %eax
movl %eax, (%ebx)
leal -12(%ebp), %eax
movl %eax, -34(%ebp)
pushl -34(%ebp)
call foo
addl $4, %esp

movl %eax, -38(%ebp)
movl $0, %eax

leave
ret
