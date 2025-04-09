#pragma once

// 5! = 5 * 4 * 3 * 2 * 1

unsigned int factorial_for(unsigned int num);
unsigned int factorial_better(unsigned int num);
unsigned int factorial_recursive(unsigned int num);

unsigned int fib_iterative(unsigned int num);
unsigned int fib_recursive(unsigned int num);

unsigned int fib_recursive_count(unsigned int num, unsigned int& callCount);
unsigned int fib_recursive_cached(unsigned int num, unsigned int& callCount, unsigned int* cache);
