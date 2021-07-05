
section		.text
			global		_ft_write
			extern		___error

_ft_write:
			mov		rax, 0x2000004	; system call
			syscall					; write
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
			
		