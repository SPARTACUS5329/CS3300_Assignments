.bss
string_glob: .space 2
.data
t11: .asciz "%s\n"
.text
.globl swap
swap:
pushl %ebp
movl %esp, %ebp
subl $42, %esp
xorl %eax, %eax
movb $0, %al
movl %eax, -4(%ebp)
movl $1, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
leal -12(%ebp, %eax), %ebx
movl -4(%ebp), %eax
movl %eax, (%ebx)
leal 8(%ebp), %eax
movl %eax, -18(%ebp)
movl $0, %eax
movl %eax, -22(%ebp)
movl -22(%ebp), %eax
leal -12(%ebp, %eax), %ebx
leal -18(%ebp), %eax
movl %eax, (%ebx)
leal 8(%ebp), %eax
movl %eax, -26(%ebp)
movl 12(%ebp), %eax
movl %eax, -30(%ebp)
movl -30(%ebp), %eax
leal 8(%ebp, %eax), %ebx
leal -26(%ebp), %eax
movl %eax, (%ebx)
leal -12(%ebp), %eax
movl %eax, -34(%ebp)
movl 16(%ebp), %eax
movl %eax, -38(%ebp)
movl -38(%ebp), %eax
leal 8(%ebp, %eax), %ebx
leal -34(%ebp), %eax
movl %eax, (%ebx)
movl $0, %eax

leave
ret
.globl permutRec
permutRec:
pushl %ebp
movl %esp, %ebp
subl $84, %esp
movl 12(%ebp), %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
xorl %eax, %eax
movl 12(%ebp), %ecx
movl $4, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -12(%ebp)
movl -12(%ebp), %ecx
cmpl $1, %ecx
je .L1
jmp .L2
.L1:
leal 8(%ebp), %eax
movl %eax, -20(%ebp)
pushl -20(%ebp)
pushl $t11
call printf
addl $8, %esp

movl %eax, -24(%ebp)
jmp .L3
.L2:
.L4:
xorl %eax, %eax
movl -8(%ebp), %ecx
movl $5, %edx
cmpl %edx, %ecx
setl %al

movl %eax, -28(%ebp)
movl -28(%ebp), %ecx
cmpl $1, %ecx
je .L5
jmp .L6
.L5:
leal 8(%ebp), %eax
movl %eax, -32(%ebp)
movl 12(%ebp), %eax
movl %eax, -36(%ebp)
movl -8(%ebp), %eax
movl %eax, -40(%ebp)
pushl -40(%ebp)
pushl -36(%ebp)
pushl -32(%ebp)
call swap
addl $12, %esp

movl %eax, -44(%ebp)
leal 8(%ebp), %eax
movl %eax, -48(%ebp)
movl 12(%ebp), %eax
addl $1, %eax
movl %eax, -52(%ebp)
movl -52(%ebp), %eax
movl %eax, -56(%ebp)
pushl -56(%ebp)
pushl -48(%ebp)
call permutRec
addl $8, %esp

movl %eax, -60(%ebp)
leal 8(%ebp), %eax
movl %eax, -64(%ebp)
movl 12(%ebp), %eax
movl %eax, -68(%ebp)
movl -8(%ebp), %eax
movl %eax, -72(%ebp)
pushl -72(%ebp)
pushl -68(%ebp)
pushl -64(%ebp)
call swap
addl $12, %esp

movl %eax, -76(%ebp)
movl -8(%ebp), %eax
addl $1, %eax
movl %eax, -80(%ebp)
movl -80(%ebp), %eax
movl %eax, -8(%ebp)
jmp .L4
.L6:
.L3:
movl $0, %eax

leave
ret
.globl permut
permut:
pushl %ebp
movl %esp, %ebp
subl $-56, %esp
leal 8(%ebp), %eax
movl %eax, -4(%ebp)
movl $0, %eax
movl %eax, -8(%ebp)
pushl -8(%ebp)
pushl -4(%ebp)
call permutRec
addl $8, %esp

movl %eax, -12(%ebp)
movl $0, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $56, %esp
xorl %eax, %eax
movb $'A', %al
movl %eax, -4(%ebp)
movl $6, %eax
movl %eax, -8(%ebp)
movl -44(%ebp), %eax
leal string_glob, %ebx
movl -4(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'B', %al
movl %eax, -12(%ebp)
movl $0, %eax
movl %eax, -16(%ebp)
movl -44(%ebp), %eax
leal string_glob, %ebx
movl -12(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'C', %al
movl %eax, -20(%ebp)
movl $0, %eax
movl %eax, -24(%ebp)
movl -44(%ebp), %eax
leal string_glob, %ebx
movl -20(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'D', %al
movl %eax, -28(%ebp)
movl $0, %eax
movl %eax, t38
movl -44(%ebp), %eax
leal string_glob, %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $'E', %al
movl %eax, -32(%ebp)
movl $0, %eax
movl %eax, -36(%ebp)
movl -44(%ebp), %eax
leal string_glob, %ebx
movl -32(%ebp), %eax
movl %eax, (%ebx)
xorl %eax, %eax
movb $0, %al
movl %eax, -40(%ebp)
movl $0, %eax
movl %eax, -44(%ebp)
movl -44(%ebp), %eax
leal string_glob, %ebx
movl -40(%ebp), %eax
movl %eax, (%ebx)
leal string_glob, %eax
movl %eax, -48(%ebp)
pushl -48(%ebp)
call permut
addl $4, %esp

movl %eax, -52(%ebp)
movl $0, %eax

leave
ret
