#pragma once


unsigned int factorial_for(unsigned int num);
unsigned int factorial_better(unsigned int num);
unsigned int factorial_recursive(unsigned int num);

unsigned int fibonacci_iterative(unsigned int num);
unsigned int fibonacci_recursive(unsigned int num);
unsigned int fibonacci_recursive_count(unsigned int num, unsigned int& count);
unsigned int fibonacci_recursive_cached(unsigned int num, unsigned int* cache, unsigned int& count);