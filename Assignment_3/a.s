.bss
.data
t5: .asciz "%s"
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $46, %esp
movb $'B', %eax
movl %eax, -4(%ebp)
movl $0, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
leal -12(%ebp, %eax), %ebx
leal -4(%ebp), %eax
movl %eax, (%ebx)
movb $0, %eax
movl %eax, -26(%ebp)
movl $1, %eax
movl %eax, -30(%ebp)
movl -30(%ebp), %eax
leal -12(%ebp, %eax), %ebx
movl -26(%ebp), %eax
movl %eax, (%ebx)
leal -12(%ebp), %eax
movl %eax, -38(%ebp)
pushl -38(%ebp)
pushl $t5
call printf
addl $8, %esp

movl %eax, -42(%ebp)
movl $0, %eax

leave
ret
