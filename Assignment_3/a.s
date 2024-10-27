.bss
.data
t1: .asciz "This is a zero\n"
t3: .asciz "This is a one\n"
t30: .asciz "Thala for a reason %d\n"
t34: .asciz "This should be zero = %d\n"
.text
.globl zero
zero:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
pushl $t1
call printf
addl $4, %esp

movl %eax, -8(%ebp)
movl $0, %eax

leave
ret
.globl one
one:
pushl %ebp
movl %esp, %ebp
subl $12, %esp
pushl $t3
call printf
addl $4, %esp

movl %eax, -8(%ebp)
movl $1, %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $220, %esp
movl $10, %eax
movl %eax, -4(%ebp)
movl -4(%ebp), %eax
movl %eax, -8(%ebp)
movl $-3, %eax
movl %eax, -12(%ebp)
movl -12(%ebp), %eax
movl %eax, -16(%ebp)
movl $-4, %eax
movl %eax, -20(%ebp)
movl -20(%ebp), %eax
movl %eax, -24(%ebp)
movl $1, %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
movl %eax, -32(%ebp)
movl $-10, %eax
movl %eax, -36(%ebp)
movl -36(%ebp), %eax
movl %eax, -40(%ebp)
movl $-17, %eax
movl %eax, -44(%ebp)
movl -44(%ebp), %eax
movl %eax, -48(%ebp)
movl $-80, %eax
movl %eax, -52(%ebp)
movl -52(%ebp), %eax
movl %eax, -56(%ebp)
movl $3, %eax
imull $3
movl %eax, -60(%ebp)
movl $3, %eax
imull $3
movl %eax, -64(%ebp)
movl -60(%ebp), %eax
imull -64(%ebp)
movl %eax, -68(%ebp)
movl -68(%ebp), %eax
movl %eax, -72(%ebp)
movl $-1, %eax
idivl $-1
movl %eax, -76(%ebp)
movl -76(%ebp), %eax
movl %eax, -80(%ebp)
movl $3, %eax
imull $5
movl %eax, -84(%ebp)
movl -84(%ebp), %eax
movl %eax, -88(%ebp)
movl $7, %eax
subl $-4, %eax
movl %eax, -92(%ebp)
movl -92(%ebp), %eax
movl %eax, -96(%ebp)
movl $1, %eax
movl %eax, -100(%ebp)
movl -100(%ebp), %eax
movl %eax, -104(%ebp)
movl -16(%ebp), %eax
imull -24(%ebp)
movl %eax, -108(%ebp)
movl -8(%ebp), %eax
addl -108(%ebp), %eax
movl %eax, -112(%ebp)
movl -112(%ebp), %eax
subl -32(%ebp), %eax
movl %eax, -116(%ebp)
movl -40(%ebp), %eax
subl -48(%ebp), %eax
movl %eax, -120(%ebp)
movl -56(%ebp), %eax
addl -72(%ebp), %eax
movl %eax, -124(%ebp)
movl -120(%ebp), %eax
idivl -124(%ebp)
movl %eax, -128(%ebp)
movl -116(%ebp), %eax
idivl -128(%ebp)
movl %eax, -132(%ebp)
movl -80(%ebp), %eax
imull -88(%ebp)
movl %eax, -136(%ebp)
movl -96(%ebp), %eax
idivl -104(%ebp)
movl %eax, -140(%ebp)
movl -136(%ebp), %eax
subl -140(%ebp), %eax
movl %eax, -144(%ebp)
movl -132(%ebp), %eax
addl -144(%ebp), %eax
movl %eax, -148(%ebp)
movl -148(%ebp), %eax
movl %eax, -152(%ebp)
movl -152(%ebp), %eax
movl %eax, -160(%ebp)
pushl -160(%ebp)
pushl $t30
call printf
addl $8, %esp

movl %eax, -164(%ebp)
movl $1, %eax
idivl $2
movl %eax, -168(%ebp)
movl -168(%ebp), %eax
movl %eax, -152(%ebp)
movl -152(%ebp), %eax
movl %eax, -176(%ebp)
pushl -176(%ebp)
pushl $t34
call printf
addl $8, %esp

movl %eax, -180(%ebp)
call zero
addl $0, %esp

movl %eax, -184(%ebp)
call one
addl $0, %esp

movl %eax, -188(%ebp)
movl -184(%ebp), %eax
idivl -188(%ebp)
movl %eax, -192(%ebp)
call one
addl $0, %esp

movl %eax, -196(%ebp)
call zero
addl $0, %esp

movl %eax, -200(%ebp)
movl -196(%ebp), %eax
addl -200(%ebp), %eax
movl %eax, -204(%ebp)
call one
addl $0, %esp

movl %eax, -208(%ebp)
movl -204(%ebp), %eax
imull -208(%ebp)
movl %eax, -212(%ebp)
movl -192(%ebp), %eax
addl -212(%ebp), %eax
movl %eax, -216(%ebp)
movl -216(%ebp), %eax
movl %eax, -152(%ebp)
movl $0, %eax

leave
ret
