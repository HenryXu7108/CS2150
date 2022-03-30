#!/bin/bash
# read in dictionary and grid
read dict
read grid

runtime1=` ./a.out $dict $grid | tail -1`
runtime2=` ./a.out $dict $grid | tail -1`
totalTime=$runtime1+$runtime2
runtime3=` ./a.out $dict $grid | tail -1`
totalTime=$totalTime+$runtime3
runtime4=` ./a.out $dict $grid | tail -1`
totalTime=$totalTime+$runtime4
runtime5=` ./a.out $dict $grid | tail -1`
totalTime=$totalTime+$runtime5
echo $((totalTime/5))
