
#include "functions.h"

unsigned int factorial_for(unsigned int num)
{
	unsigned int product = 1;

	for (unsigned int i = 2; i <= num; i++)
	{
		product *= i;
	}

	return product;
}

unsigned int factorial_better(unsigned int num)
{
	unsigned int product = 1;

	while (num > 1)
	{
		product *= num;
		num--;
	}

	return product;
}

unsigned int factorial_recursive(unsigned int num)
{
	// base/terminating case
	if (num <= 1)
	{
		return 1;
	}

	// recursive case (self call) -- WITH a state change towards the base
	else
	{
		// n! = n * (n-1)!
		return num * factorial_recursive(num - 1);
	}

}

// 0 1 *2* 3 4 5 6
// 0 1 *1* 2 3 5 8
unsigned int fib_iterative(unsigned int num)
{
	unsigned int current = 0;
	unsigned int oneBack = 1;
	unsigned int twoBack = 0;

	for (int i = 2; i <= num; i++)
	{
		current = oneBack + twoBack;
		twoBack = oneBack;
		oneBack = current;
	}
	return current;
}

unsigned int fib_recursive(unsigned int num)
{
	// Base caseS -- plural! - the 1st two terms
	if (num <= 1)
	{
		return num;
	}

	// Recursive case --- has TWO recursive calls with diff state changes
	return fib_recursive(num - 1) + fib_recursive(num - 2);
}

unsigned int fib_recursive_count(unsigned int num, unsigned int& callCount)
{
	callCount++;

	// Base caseS -- plural! - the 1st two terms
	if (num <= 1)
	{
		return num;
	}

	// Recursive case --- has TWO recursive calls with diff state changes
	return fib_recursive_count(num - 1, callCount) + fib_recursive_count(num - 2, callCount);
}


unsigned int fib_recursive_cached(unsigned int num, unsigned int& callCount, unsigned int* cache)
{
	callCount++;

	if (num == 0 || cache[num] != 0)
	{
		return cache[num];
	}

	// Base caseS -- plural! - the 1st two terms
	if (num <= 1)
	{
		cache[num] = num;
	}
	else
	{
		// Recursive case --- has TWO recursive calls with diff state changes
		cache[num] = fib_recursive_cached(num - 1, callCount, cache)
			+ fib_recursive_cached(num - 2, callCount, cache);
	}
	return cache[num];
}