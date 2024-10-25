.bss
b: .space 4
.data
t10: .asciz "Something\n"
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
subl $52, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movl $17, %eax
movl %eax, -12(%ebp)
movl -12(%ebp), %eax
movl %eax, b
movl $2, %eax
movl %eax, -16(%ebp)
pushl -16(%ebp)
call foo
addl $4, %esp

movl %eax, -20(%ebp)
movl b, %eax
movl %eax, -24(%ebp)
pushl -24(%ebp)
call foo
addl $4, %esp

movl %eax, -28(%ebp)
cmpl -8(%ebp), $3
setz %al
movzbl %al, %eax
movl %eax, -32(%ebp)
cmpl -32(%ebp), $1
je L1
jmp L2
L1:
movl $3, %eax
movl %eax, -36(%ebp)
movl -36(%ebp), %eax
movl %eax, -8(%ebp)
jmp L3
L2:
movl $2, %eax
movl %eax, -40(%ebp)
movl -40(%ebp), %eax
movl %eax, -8(%ebp)
L3:
pushl $t10
call printf
addl $4, %esp

movl %eax, -48(%ebp)
movl $0, %eax

leave
ret
