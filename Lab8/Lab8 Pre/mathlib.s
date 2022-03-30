;mathlib.s;

	global product
	global power

	section .text

product:
	xor	rax,rax		;zero out the return register
	xor	r10,r10		;zero out the counter i
start:
	cmp 	r10, rsi	;if i==second para
	je	done		;goto done
	add	rax, rdi	;sum+=first para
	inc	r10		;i+=1
	jmp	start		;back to loop
done:
	ret


power:
	xor	rax, rax	;zero out the return register
	xor	r10, r10	;zero out the counter i
	mov	rax, 1
recursive:
	cmp	rsi, 0		;if rsi==0
	je	end 		;goto end
	dec	rsi		;i--
	call 	power
	mov	rsi, rax	;rsi = power(x,x-1)
	call 	product		;radi*power(x,x-1)
end:
	ret
