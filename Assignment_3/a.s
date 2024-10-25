.bss
b: .space 4
i: .space 4
s: .space 1
.data
t7: .asciz "Hello"
.text
.global foo
foo:
pushl %ebp
movl %esp, %ebp
subl $4, %esp
movl $0, %eax

leave
ret
.global main
main:
pushl %ebp
movl %esp, %ebp
subl $44, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
cmpl -8(%ebp), $3
setz %al
movzbl %al, %eax
movl %eax, -12(%ebp)
cmpl -12(%ebp), $1
je L1
jmp L2
L1:
movl $2, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
movl %eax, -8(%ebp)
jmp L3
L2:
movl $1, %eax
movl %eax, -20(%ebp)
movl -20(%ebp), %eax
movl %eax, -8(%ebp)
L3:
movb $'A', %eax
movl %eax, -24(%ebp)
movl $0, %eax
movl %eax, -28(%ebp)
movl -24(%ebp), %eax
movl %eax, -32(%ebp)
pushl -36(%ebp)
call printf

movl %eax, -40(%ebp)
movl $0, %eax

leave
ret
