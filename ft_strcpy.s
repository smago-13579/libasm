

section     .text
            global		_ft_strcpy

_ft_strcpy:	
			mov		rcx, 			 0			;
			mov		rax, 			 0			;
	loop:	cmp		byte[rsi + rcx], 0			; 
			je		end							; if equal 
			mov 	al, byte[rsi + rcx]			; copy char from src
			mov		byte[rdi + rcx], al 		; copy char to dest
			inc		rcx							; rcx++
			jmp	loop

	end:	mov		al, byte[rsi + rcx]			; copy last char from src '\0'
			mov		byte[rdi + rcx], al 		; copy last char to dest
			mov		rax, rdi					;
			ret

			