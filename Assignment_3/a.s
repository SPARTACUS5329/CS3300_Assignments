.bss
.data
t5: .asciz "%d "
t10: .asciz "\n"
.text
.globl main
.main:
pushl %ebp
movl %esp, %ebp
subl $60, %esp
movl $0, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
.L1:
xorl %eax, %eax
movl -8(%ebp), %ecx
cmpl %ecx, $3
setl %al

movl %eax, -12(%ebp)
movl -12(%ebp), %ecx
cmpl %ecx, $1
je .L2
jmp .L3
.L2:
movl $0, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
movl %eax, -20(%ebp)
.L4:
xorl %eax, %eax
movl -20(%ebp), %ecx
cmpl %ecx, $3
setl %al

movl %eax, -24(%ebp)
movl -24(%ebp), %ecx
cmpl %ecx, $1
je .L5
jmp .L6
.L5:
movl -8(%ebp), %eax
imull -20(%ebp), %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
movl %eax, -36(%ebp)
pushl -36(%ebp)
pushl $t5
call printf
addl $8, %esp

movl %eax, -40(%ebp)
movl -20(%ebp), %eax
addl $1, %eax
movl %eax, -44(%ebp)
movl -44(%ebp), %eax
movl %eax, -20(%ebp)
jmp .L4
.L6:
pushl $t10
call printf
addl $4, %esp

movl %eax, -52(%ebp)
movl -8(%ebp), %eax
addl $1, %eax
movl %eax, -56(%ebp)
movl -56(%ebp), %eax
movl %eax, -8(%ebp)
jmp .L1
.L3:
movl $0, %eax

leave
ret
