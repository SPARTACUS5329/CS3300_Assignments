.bss
.data
t3: .asciz "No printing\n"
t10: .asciz "I love 3s\n"
.text
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $56, %esp
xorl %eax, %eax
movl $1, %ecx
movl $0, %edx
cmpl %ecx, %edx
setg %al

movl %eax, -4(%ebp)
movl -4(%ebp), %ecx
cmpl $1, %ecx
je .L1
jmp .L2
.L1:
xorl %eax, %eax
movl $2, %ecx
movl $0, %edx
cmpl %ecx, %edx
setl %al

movl %eax, -8(%ebp)
movl -8(%ebp), %ecx
cmpl $1, %ecx
je .L3
jmp .L4
.L3:
pushl $t3
call printf
addl $4, %esp

movl %eax, -16(%ebp)
jmp .L5
.L4:
xorl %eax, %eax
movl $3, %ecx
movl $0, %edx
cmpl %ecx, %edx
setg %al

movl %eax, -20(%ebp)
movl -20(%ebp), %ecx
cmpl $1, %ecx
je .L6
jmp .L7
.L6:
xorl %eax, %eax
movl $0, %ecx
movl $0, %edx
cmpl %ecx, %edx
sete %al

movl %eax, -24(%ebp)
movl -24(%ebp), %ecx
cmpl $1, %ecx
je .L8
jmp .L9
.L8:
movl $3, %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
movl %eax, -32(%ebp)
.L10:
movl -32(%ebp), %eax
imull -32(%ebp), %eax
movl %eax, -36(%ebp)
xorl %eax, %eax
movl -36(%ebp), %ecx
movl $6561, %edx
cmpl %ecx, %edx
setle %al

movl %eax, -40(%ebp)
movl -40(%ebp), %ecx
cmpl $1, %ecx
je .L11
jmp .L12
.L11:
pushl $t10
call printf
addl $4, %esp

movl %eax, -48(%ebp)
movl -32(%ebp), %eax
imull -32(%ebp), %eax
movl %eax, -52(%ebp)
movl -52(%ebp), %eax
movl %eax, -32(%ebp)
jmp .L10
.L12:
.L9:
.L7:
.L5:
.L2:
movl $0, %eax

leave
ret
