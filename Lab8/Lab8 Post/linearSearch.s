;linearSearch.s
;Parameter 1 rdi = pointer to the int array
;Parameter 2 rsi = int size of the array
;Parameter 2 rdx = the target to find in the array 
;Return value is a int that is the iterator of the target in the array


	global linearSearch

	section .text

linearSearch:
	xor	r10, r10	;zero out counter i
	xor	rax, rax	

start:
	cmp	r10, rsi	 ;if i==size
	je	notFound	 ;goto notFound
	cmp	edx, [rdi+4*r10] ;compare target with arr[i]
	je	done		 ;goto done
	inc	r10		 ;i++
	jmp	start		 ;back to start
done:
	mov	rax, r10
	ret
notFound:
	mov	rax, -1
	ret
