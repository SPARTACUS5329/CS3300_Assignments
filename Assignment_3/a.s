.bss
.data
t6: .asciz "  "
t13: .asciz "   %d"
t16: .asciz "  %d"
t23: .asciz "\n"
.text
.globl printPascal
printPascal:
pushl %ebp
movl %esp, %ebp
subl $116, %esp
movl $1, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
.L1:
xorl %eax, %eax
movl -8(%ebp), %ecx
movl 8(%ebp), %edx
cmpl %edx, %ecx
setle %al

movl %eax, -12(%ebp)
movl -12(%ebp), %ecx
cmpl $1, %ecx
je .L2
jmp .L3
.L2:
movl $1, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
movl %eax, -20(%ebp)
.L4:
movl 8(%ebp), %eax
subl -8(%ebp), %eax
movl %eax, -24(%ebp)
xorl %eax, %eax
movl -20(%ebp), %ecx
movl -24(%ebp), %edx
cmpl %edx, %ecx
setle %al

movl %eax, -28(%ebp)
movl -28(%ebp), %ecx
cmpl $1, %ecx
je .L5
jmp .L6
.L5:
pushl $t6
call printf
addl $4, %esp

movl %eax, -36(%ebp)
movl -20(%ebp), %eax
addl $1, %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
movl %eax, -20(%ebp)
jmp .L4
.L6:
movl $1, %eax
movl %eax, -44(%ebp)
movl -44(%ebp), %eax
movl %eax, -48(%ebp)
movl $1, %eax
movl %eax, -52(%ebp)
movl -52(%ebp), %eax
movl %eax, -56(%ebp)
.L7:
xorl %eax, %eax
movl -56(%ebp), %ecx
movl -8(%ebp), %edx
cmpl %edx, %ecx
setle %al

movl %eax, -60(%ebp)
movl -60(%ebp), %ecx
cmpl $1, %ecx
je .L8
jmp .L9
.L8:
xorl %eax, %eax
movl -48(%ebp), %ecx
movl $10, %edx
cmpl %edx, %ecx
setl %al

movl %eax, -64(%ebp)
movl -64(%ebp), %ecx
cmpl $1, %ecx
je .L10
jmp .L11
.L10:
movl -48(%ebp), %eax
movl %eax, -68(%ebp)
pushl -68(%ebp)
pushl line
call printf
addl $8, %esp

movl %eax, -72(%ebp)
jmp .L12
.L11:
movl -48(%ebp), %eax
movl %eax, -80(%ebp)
pushl -80(%ebp)
pushl $t16
call printf
addl $8, %esp

movl %eax, -84(%ebp)
.L12:
movl -8(%ebp), %eax
subl -56(%ebp), %eax
movl %eax, -88(%ebp)
movl -48(%ebp), %eax
imull -88(%ebp), %eax
movl %eax, -92(%ebp)
movl -92(%ebp), %eax
xorl %edx, %edx
movl -56(%ebp), %ebx
idivl %ebx
movl %eax, -96(%ebp)
movl -96(%ebp), %eax
movl %eax, -48(%ebp)
movl -56(%ebp), %eax
addl $1, %eax
movl %eax, -100(%ebp)
movl -100(%ebp), %eax
movl %eax, -56(%ebp)
jmp .L7
.L9:
pushl $t23
call printf
addl $4, %esp

movl %eax, -108(%ebp)
movl -8(%ebp), %eax
addl $1, %eax
movl %eax, -112(%ebp)
movl -112(%ebp), %eax
movl %eax, -8(%ebp)
jmp .L1
.L3:
movl $0, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
movl $6, %eax
movl %eax, -4(%ebp)
pushl -4(%ebp)
call printPascal
addl $4, %esp

movl %eax, -8(%ebp)
movl $0, %eax

leave
ret
