;threexplusone.s
; Optimization:
;replace imul rdi,3 and inc rdi with lea for 3x+1
; 

	global threexplusone
	section.data
	

	section.text
;Parameter 1 is the input positive integer rdi

threexplusone:
	xor	rax, rax
	cmp	rdi, 1		;if input=1, goto done
	je 	done
	test	rdi, 1		;if input is odd
	jnz	odd		;goto odd
	jz	even		;else goto even
odd:
	lea	rdi, [rdi*3+1]		;input = 3x+1
	call 	threexplusone
	inc	rax
	jmp	done
	
even:	
	shr	rdi, 1		;input = x/2
	call 	threexplusone
	inc	rax
	jmp	done
done:
	ret
	



	
