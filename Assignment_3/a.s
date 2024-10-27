.bss
.data
t1: .asciz "%d\n"
.text
.globl print
print:
pushl %ebp
movl %esp, %ebp
subl $20, %esp
movl 8(%ebp), %eax
movl %eax, -8(%ebp)
pushl -8(%ebp)
pushl $t1
call printf
addl $8, %esp

movl %eax, -12(%ebp)
movl 8(%ebp), %eax
addl 12(%ebp), %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax

leave
ret
.globl main
main:
pushl %ebp
movl %esp, %ebp
subl $184, %esp
movl $3, %eax
movl %eax, -4(%ebp)
movl $9, %eax
movl %eax, -8(%ebp)
pushl -8(%ebp)
pushl -4(%ebp)
call print
addl $8, %esp

movl %eax, -12(%ebp)
movl -12(%ebp), %eax
movl %eax, -16(%ebp)
movl $4, %eax
movl %eax, -20(%ebp)
movl $-9, %eax
movl %eax, -24(%ebp)
pushl -24(%ebp)
pushl -20(%ebp)
call print
addl $8, %esp

movl %eax, -28(%ebp)
movl -28(%ebp), %eax
movl %eax, -32(%ebp)
pushl -32(%ebp)
pushl -16(%ebp)
call print
addl $8, %esp

movl %eax, -36(%ebp)
movl -36(%ebp), %eax
movl %eax, -40(%ebp)
movl $0, %eax
movl %eax, -44(%ebp)
movl $67, %eax
movl %eax, -48(%ebp)
pushl -48(%ebp)
pushl -44(%ebp)
call print
addl $8, %esp

movl %eax, -52(%ebp)
movl -52(%ebp), %eax
movl %eax, -56(%ebp)
movl $7, %eax
movl %eax, -60(%ebp)
movl $8, %eax
movl %eax, -64(%ebp)
pushl -64(%ebp)
pushl -60(%ebp)
call print
addl $8, %esp

movl %eax, -68(%ebp)
movl -68(%ebp), %eax
movl %eax, -72(%ebp)
pushl -72(%ebp)
pushl -56(%ebp)
call print
addl $8, %esp

movl %eax, -76(%ebp)
movl -76(%ebp), %eax
movl %eax, -80(%ebp)
movl $3, %eax
movl %eax, -84(%ebp)
movl $9, %eax
movl %eax, -88(%ebp)
pushl -88(%ebp)
pushl -84(%ebp)
call print
addl $8, %esp

movl %eax, -92(%ebp)
movl -92(%ebp), %eax
movl %eax, -96(%ebp)
movl $4, %eax
movl %eax, -100(%ebp)
movl $-9, %eax
movl %eax, -104(%ebp)
pushl -104(%ebp)
pushl -100(%ebp)
call print
addl $8, %esp

movl %eax, -108(%ebp)
movl -108(%ebp), %eax
movl %eax, -112(%ebp)
pushl -112(%ebp)
pushl -96(%ebp)
call print
addl $8, %esp

movl %eax, -116(%ebp)
movl -116(%ebp), %eax
movl %eax, -120(%ebp)
pushl -120(%ebp)
pushl -80(%ebp)
call print
addl $8, %esp

movl %eax, -124(%ebp)
movl -124(%ebp), %eax
movl %eax, -128(%ebp)
pushl -128(%ebp)
pushl -40(%ebp)
call print
addl $8, %esp

movl %eax, -132(%ebp)
movl -132(%ebp), %eax
movl %eax, -136(%ebp)
movl $-1, %eax
movl %eax, -140(%ebp)
movl $-3, %eax
movl %eax, -144(%ebp)
pushl -144(%ebp)
pushl -140(%ebp)
call print
addl $8, %esp

movl %eax, -148(%ebp)
movl -148(%ebp), %eax
movl %eax, -152(%ebp)
movl $2, %eax
movl %eax, -156(%ebp)
movl $5, %eax
movl %eax, -160(%ebp)
pushl -160(%ebp)
pushl -156(%ebp)
call print
addl $8, %esp

movl %eax, -164(%ebp)
movl -164(%ebp), %eax
movl %eax, -168(%ebp)
pushl -168(%ebp)
pushl -152(%ebp)
call print
addl $8, %esp

movl %eax, -172(%ebp)
movl -172(%ebp), %eax
movl %eax, -176(%ebp)
pushl -176(%ebp)
pushl -136(%ebp)
call print
addl $8, %esp

movl %eax, -180(%ebp)
movl $0, %eax

leave
ret
