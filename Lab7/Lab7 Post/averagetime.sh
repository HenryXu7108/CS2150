#!/bin/bash
#include <stdio.h>
echo "enter the exponent for counter.cpp:"

read exp


if [[ "$exp"="quit" ]]; then
   

    clang++ counter.cpp timer.cpp
    i=1
    total=0

    while [ $i -lt 6 ]; do
	runtime=`./a.out $exp | tail -1`
	echo "Running iteration" $i"..."
	echo "time taken: " $runtime
	total=$((total+runtime))
	let i=i+1
    done
    
    echo "5 iterations took " $total "ms"
    echo "Average time was "$((total/5)) "ms"
fi
