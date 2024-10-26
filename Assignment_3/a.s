.bss
.data
t25: .asciz "%s\n"
.text
.globl main
.main:
pushl %ebp
movl %esp, %ebp
subl $134, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movl $7, %eax
movl %eax, -12(%ebp)
movl -12(%ebp), %eax
movl %eax, -16(%ebp)
xorl %eax, %eax
movl -8(%ebp), %ecx
cmpl %ecx, $3
setle %al

movl %eax, -20(%ebp)
movl -20(%ebp), %ecx
cmpl %ecx, $1
je .L3
jmp .L2
.L3:
xorl %eax, %eax
movl -16(%ebp), %ecx
cmpl %ecx, $7
sete %al

movl %eax, -24(%ebp)
movl -24(%ebp), %ecx
cmpl %ecx, $1
je .L1
jmp .L2
.L1:
movb $'P', %eax
movl %eax, -28(%ebp)
movl $0, %eax
movl %eax, -32(%ebp)
movl -32(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -28(%ebp), %eax
movl %eax, (%ebx)
movb $'R', %eax
movl %eax, -50(%ebp)
movl $1, %eax
movl %eax, -54(%ebp)
movl -54(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -50(%ebp), %eax
movl %eax, (%ebx)
movb $'O', %eax
movl %eax, -58(%ebp)
movl $2, %eax
movl %eax, -62(%ebp)
movl -62(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -58(%ebp), %eax
movl %eax, (%ebx)
movb $0, %eax
movl %eax, -66(%ebp)
movl $3, %eax
movl %eax, -70(%ebp)
movl -70(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -66(%ebp), %eax
movl %eax, (%ebx)
jmp .L4
.L2:
movb $'N', %eax
movl %eax, -74(%ebp)
movl $0, %eax
movl %eax, -78(%ebp)
movl -78(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -74(%ebp), %eax
movl %eax, (%ebx)
movb $'O', %eax
movl %eax, -82(%ebp)
movl $1, %eax
movl %eax, -86(%ebp)
movl -86(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -82(%ebp), %eax
movl %eax, (%ebx)
movb $'O', %eax
movl %eax, -90(%ebp)
movl $2, %eax
movl %eax, -94(%ebp)
movl -94(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -90(%ebp), %eax
movl %eax, (%ebx)
movb $'B', %eax
movl %eax, -98(%ebp)
movl $3, %eax
movl %eax, -102(%ebp)
movl -102(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -98(%ebp), %eax
movl %eax, (%ebx)
movb $'S', %eax
movl %eax, -106(%ebp)
movl $4, %eax
movl %eax, -110(%ebp)
movl -110(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -106(%ebp), %eax
movl %eax, (%ebx)
movb $0, %eax
movl %eax, -114(%ebp)
movl $5, %eax
movl %eax, -118(%ebp)
movl -118(%ebp), %eax
leal -36(%ebp, %eax), %ebx
movl -114(%ebp), %eax
movl %eax, (%ebx)
.L4:
leal -36(%ebp), %eax
movl %eax, -126(%ebp)
pushl -126(%ebp)
pushl $t25
call printf
addl $8, %esp

movl %eax, -130(%ebp)
movl $0, %eax

leave
ret
