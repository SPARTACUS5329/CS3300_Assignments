.bss
.data
t7: .asciz "Something\n"
.text
.globl foo
foo:
pushl %ebp
movl %esp, %ebp
subl $4, %esp
movl $0, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $40, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movl $2, %eax
movl %eax, -12(%ebp)
pushl -12(%ebp)
call foo
addl $4, %esp

movl %eax, -16(%ebp)
cmpl -8(%ebp), $3
setz %al
movzbl %al, %eax
movl %eax, -20(%ebp)
cmpl -20(%ebp), $1
je L1
jmp L2
L1:
movl $3, %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %eax
movl %eax, -8(%ebp)
jmp L3
L2:
movl $2, %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
movl %eax, -8(%ebp)
L3:
pushl t7
call printf
addl $4, %esp

movl %eax, -36(%ebp)
movl $0, %eax

leave
ret
