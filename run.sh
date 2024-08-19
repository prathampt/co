#!/bin/bash

# # Without Optimization
# echo
# echo "Compiling the 'matrixMultiply.c' without optimization: gcc matrixMultiply.c -o matrixMultiply"
# gcc matrixMultiply.c -o matrixMultiply
# echo "Results:"
# ./matrixMultiply

# # With Optimization
# echo
# echo "Compiling the 'matrixMultiply.c' with optimization: gcc -O3 matrixMultiply.c -o matrixMultiply"
# gcc -O3 matrixMultiply.c -o matrixMultiply
# echo "Results:"
# ./matrixMultiply

# Using 'perf' command to analyse the cache miss

lscpu | grep "Model name"
echo
echo "Compiling rowMajor.c"
gcc -O3 rowMajor.c -o rowMajor
echo "Compiling columnMajor.c"
gcc -O3 columnMajor.c -o columnMajor

sudo sysctl -w kernel.perf_event_paranoid=1 # Setting it to 1 will allow CPU event access but still disallow raw and ftrace function tracepoint access.

echo "perf stat for rowMajor"
perf stat -e cache-misses ./rowMajor

echo "perf stat for columnMajor"
perf stat -e cache-misses ./columnMajor