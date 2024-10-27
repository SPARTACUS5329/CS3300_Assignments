.bss
a: .space 4
b: .space 4
.data
t2: .asciz "12\n"
t5: .asciz "52\n"
t8: .asciz "77\n"
t11: .asciz "8234\n"
t19: .asciz "1241\n"
t21: .asciz "-1241\n"
t27: .asciz "2445\n"
t29: .asciz "-2445\n"
t35: .asciz "4562"
t37: .asciz "-4562"
t43: .asciz "352"
t45: .asciz "-352"
t51: .asciz "986"
t53: .asciz "-986"
t55: .asciz "\n"
.text
.globl set_a
set_a:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $1, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, a
pushl $t2
call printf
addl $4, %esp

movl %eax, -12(%ebp)
movl $1, %eax

leave
ret
.globl set_b
set_b:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $1, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, b
pushl $t5
call printf
addl $4, %esp

movl %eax, -12(%ebp)
movl $1, %eax

leave
ret
.globl unset_a
unset_a:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $0, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, a
pushl $t8
call printf
addl $4, %esp

movl %eax, -12(%ebp)
movl a, %eax

leave
ret
.globl unset_b
unset_b:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $0, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, b
pushl $t11
call printf
addl $4, %esp

movl %eax, -12(%ebp)
movl a, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $176, %esp
movl $0, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, a
movl $0, %eax
movl %eax, -8(%ebp)
movl -8(%ebp), %eax
movl %eax, b
call set_a
addl $0, %esp

movl %eax, -12(%ebp)
xorl %eax, %eax
movl -12(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -16(%ebp)
movl -16(%ebp), %ecx
cmpl $1, %ecx
je .L3
jmp .L2
.L3:
call set_b
addl $0, %esp

movl %eax, -20(%ebp)
xorl %eax, %eax
movl -20(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -24(%ebp)
movl -24(%ebp), %ecx
cmpl $1, %ecx
je .L1
jmp .L2
.L1:
pushl $t19
call printf
addl $4, %esp

movl %eax, t20
jmp .L4
.L2:
pushl $t21
call printf
addl $4, %esp

movl %eax, -36(%ebp)
.L4:
call set_b
addl $0, %esp

movl %eax, -40(%ebp)
xorl %eax, %eax
movl -40(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -44(%ebp)
movl -44(%ebp), %ecx
cmpl $1, %ecx
je .L7
jmp .L6
.L7:
call set_a
addl $0, %esp

movl %eax, -48(%ebp)
xorl %eax, %eax
movl -48(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -52(%ebp)
movl -52(%ebp), %ecx
cmpl $1, %ecx
je .L5
jmp .L6
.L5:
pushl $t27
call printf
addl $4, %esp

movl %eax, -60(%ebp)
jmp .L8
.L6:
pushl $t29
call printf
addl $4, %esp

movl %eax, -68(%ebp)
.L8:
call unset_a
addl $0, %esp

movl %eax, -72(%ebp)
xorl %eax, %eax
movl -72(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -76(%ebp)
movl -76(%ebp), %ecx
cmpl $1, %ecx
je .L11
jmp .L10
.L11:
call unset_b
addl $0, %esp

movl %eax, -80(%ebp)
xorl %eax, %eax
movl -80(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -84(%ebp)
movl -84(%ebp), %ecx
cmpl $1, %ecx
je .L9
jmp .L10
.L9:
pushl $t35
call printf
addl $4, %esp

movl %eax, -92(%ebp)
jmp .L12
.L10:
pushl $t37
call printf
addl $4, %esp

movl %eax, -100(%ebp)
.L12:
call unset_b
addl $0, %esp

movl %eax, -104(%ebp)
xorl %eax, %eax
movl -104(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -108(%ebp)
movl -108(%ebp), %ecx
cmpl $1, %ecx
je .L15
jmp .L14
.L15:
call set_a
addl $0, %esp

movl %eax, -112(%ebp)
xorl %eax, %eax
movl -112(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -116(%ebp)
movl -116(%ebp), %ecx
cmpl $1, %ecx
je .L13
jmp .L14
.L13:
pushl $t43
call printf
addl $4, %esp

movl %eax, -124(%ebp)
jmp .L16
.L14:
pushl $t45
call printf
addl $4, %esp

movl %eax, -132(%ebp)
.L16:
call set_b
addl $0, %esp

movl %eax, -136(%ebp)
xorl %eax, %eax
movl -136(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -140(%ebp)
movl -140(%ebp), %ecx
cmpl $1, %ecx
je .L19
jmp .L18
.L19:
call unset_a
addl $0, %esp

movl %eax, -144(%ebp)
xorl %eax, %eax
movl -144(%ebp), %ecx
movl $1, %edx
cmpl %edx, %ecx
sete %al

movl %eax, -148(%ebp)
movl -148(%ebp), %ecx
cmpl $1, %ecx
je .L17
jmp .L18
.L17:
pushl $t51
call printf
addl $4, %esp

movl %eax, -156(%ebp)
jmp .L20
.L18:
pushl $t53
call printf
addl $4, %esp

movl %eax, -164(%ebp)
.L20:
pushl $t55
call printf
addl $4, %esp

movl %eax, -172(%ebp)
movl $0, %eax

leave
ret
