
section		.text
			global		_ft_strdup
            extern      _malloc
            extern      _ft_strlen
            extern      _ft_strcpy

_ft_strdup:
            call        _ft_strlen          ; call ft_strlen, len in rax
            add         rax,		1		; add for '\0'
			push		rdi					; mov rdi to stack
			mov			rdi,		rax		; len in rdi
			call		_malloc				; call malloc, str in rax
			cmp			rax,		0		; if memory wasn't allocated
			je			exit				;
			mov			rdi,		rax		;
			pop			rsi					; receive from stack
			call		_ft_strcpy			; call ft_strcpy, ret in rax
			ret								;

exit:		
			ret

