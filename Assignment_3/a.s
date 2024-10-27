.bss
.data
t4: .asciz "c = %d\n"
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $40, %esp
movl $10, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movl $20, %eax
movl %eax, -12(%ebp)
movl -12(%ebp), %eax
movl %eax, -16(%ebp)
movl -8(%ebp), %eax
addl -16(%ebp), %eax
movl %eax, -20(%ebp)
movl -20(%ebp), %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %eax
movl %eax, -32(%ebp)
pushl -32(%ebp)
pushl $t4
call printf
addl $8, %esp

movl %eax, -36(%ebp)
movl $0, %eax

leave
ret
