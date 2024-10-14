.data
fmt:	.asciz "c = %d\n"

	.text
	.globl main
main:
	pushl %ebp                 # Prologue
	movl %esp, %ebp                
	subl $12, %esp             # Space for local variables (3)

	movl $10, -12(%ebp)        # Assign a = 10
	movl $20, -8(%ebp)         # Assign b = 20

	movl -12(%ebp), %eax       # Load a
	addl -8(%ebp), %eax        # b with a

	movl %eax, -4(%ebp)        # Store the sum to c

	pushl -4(%ebp)             # Push c as second arg
	pushl $fmt                 # Push address of fmt as arg
	call printf                # Function call

	movl $0, %eax              # Return value 0
	leave                      # Epilogue
	ret