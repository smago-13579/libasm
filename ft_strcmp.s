
section		.text
			global		_ft_strcmp

_ft_strcmp:
			mov 	rcx,				0;
			mov 	rax,				0;
			mov 	rdx,				0;
	loop:	cmp		byte[rdi + rcx], 	0; compare s1 && '\0'
			je		end					 ; if equal move to end
			cmp 	byte[rsi + rcx], 	0; compare s2 && '\0'
			je		end					 ; if equal move to end
			mov 	al, byte[rdi + rcx]	 ; copy char from s1 to al
			cmp 	byte[rsi + rcx], al	 ; compare al && s2
			jne 	end				     ; if not equal move to end
			inc		rcx					 ; rcx++
			jmp 	loop

	end:	movsx 	rax, byte[rdi + rcx] ;
			movsx 	rdx, byte[rsi + rcx] ;
			sub		rax, rdx			 ;
			ret							 ;
			