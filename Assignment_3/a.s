.bss
b: .space 4
i: .space 4
s: .space 1
.text
.global foo
foo:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
movl 8(%ebp), %eax
movl %eax, -4(%ebp)
pushl -4(%ebp)
call foo

movl %eax, -8(%ebp)
movl $0, %eax

leave
ret
.global main
main:
pushl %ebp
movl %esp, %ebp
subl $24, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
cmpl $3, -8(%ebp)
setz %al
movzbl %al, %eax
movl %eax, -12(%ebp)
jmp L2
L1:
movl -8(%ebp), %eax
movl %eax, -16(%ebp)
pushl -16(%ebp)
call foo

movl %eax, -20(%ebp)
L2:
movl $0, %eax

leave
ret
