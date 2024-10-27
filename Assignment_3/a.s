.bss
.data
t2: .asciz "Value at b is %d\n"
t5: .asciz "Current Nesting: %d\n"
t10: .asciz "Arg before is %d\n"
t16: .asciz "Arg after is %d\n"
t23: .asciz "Back to Nesting: %d\n"
.text
.globl b
b:
pushl %ebp
movl %esp, %ebp
subl $20, %esp
movl 8(%ebp), %eax
imull 8(%ebp), %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, 8(%ebp)
movl 8(%ebp), %eax
movl %eax, -12(%ebp)
pushl -12(%ebp)
pushl $t2
call printf
addl $8, %esp

movl %eax, -16(%ebp)
movl $0, %eax

leave
ret
.globl a
a:
pushl %ebp
movl %esp, %ebp
subl $88, %esp
movl 12(%ebp), %eax
movl %eax, -8(%ebp)
pushl -8(%ebp)
pushl $t5
call printf
addl $8, %esp

movl %eax, -12(%ebp)
movl $1024, %eax
imull $1024, %eax
movl %eax, -16(%ebp)
xorl %eax, %eax
movl 8(%ebp), %ecx
movl -16(%ebp), %edx
cmpl %edx, %ecx
setge %al

movl %eax, -20(%ebp)
movl -20(%ebp), %ecx
cmpl $1, %ecx
je .L1
jmp .L2
.L1:
jmp .L3
.L2:
movl 8(%ebp), %eax
movl %eax, -28(%ebp)
pushl -28(%ebp)
pushl $t10
call printf
addl $8, %esp

movl %eax, -32(%ebp)
movl 8(%ebp), %eax
movl %eax, -36(%ebp)
pushl -36(%ebp)
call b
addl $4, %esp

movl %eax, -40(%ebp)
movl 8(%ebp), %eax
imull $1024, %eax
movl %eax, -44(%ebp)
movl -44(%ebp), %eax
movl %eax, 8(%ebp)
movl 8(%ebp), %eax
movl %eax, -52(%ebp)
pushl -52(%ebp)
pushl $t16
call printf
addl $8, %esp

movl %eax, -56(%ebp)
movl 8(%ebp), %eax
movl %eax, -60(%ebp)
movl 12(%ebp), %eax
addl $1, %eax
movl %eax, -64(%ebp)
movl -64(%ebp), %eax
movl %eax, -68(%ebp)
pushl -68(%ebp)
pushl -60(%ebp)
call a
addl $8, %esp

movl %eax, -72(%ebp)
movl 12(%ebp), %eax
movl %eax, -80(%ebp)
pushl -80(%ebp)
pushl $t23
call printf
addl $8, %esp

movl %eax, -84(%ebp)
.L3:
movl $0, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $100, %eax
movl %eax, -4(%ebp)
movl $1, %eax
movl %eax, -8(%ebp)
pushl -8(%ebp)
pushl -4(%ebp)
call a
addl $8, %esp

movl %eax, -12(%ebp)
movl $0, %eax

leave
ret
