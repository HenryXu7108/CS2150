;binarySearch.sb
;Parameter 1 = pointer to the int array rdi
;Parameter 2 = int of the beginning of the array rsi
;Parameter 3 = int of the ending of the array rdx
;Parameter 4 = target to find rcx 
;Return value is the index of the target, -1 if target not in the array 


	global binarySearch

	section .text

binarySearch:
	xor	r10, r10	;zero out i
	cmp	rsi, rdx	;if(left == right) goto notFound
	jg	notFound
	lea	r10, [rsi+rdx]	;i = (left+right)/2
	shr	r10, 1
	cmp	ecx, [rdi+r10*4] ;compare target with arr[mid]
	je	done		 ;if target = arr[mid], goto done
	jl	left		 ;if target < arr[mid] goto left
	jg	right		 ;if target > arr[mid] goto right

left:
	mov 	rdx, r10	;right = mid
	dec	rdx
	
	jmp	binarySearch
right:
	mov	rsi, r10	;left = mid
	inc	rsi
	jmp	binarySearch

done:	
	mov	rax, r10	;return the index
	ret
notFound:
	mov	rax, -1
	ret
