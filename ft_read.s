
section		.text
			global		_ft_read
			extern		___error

_ft_read:
			mov		rax, 0x2000003	; system call
			syscall					; read
			jc		error			; if write fail
			jmp		exit			;

error:
			push	rax				; push to stack
			call 	___error		;
			pop		r8				; receive from stack #error
			mov		[rax], r8		; address equal r8
			mov		rax, -1			; return (-1)
			ret 			

exit:
			ret
		