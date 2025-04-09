#include "functions.h"


// 5! = 1 * 2 * 3 * 4 * 5
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
	// base/terminating/exit case
	if (num <= 1)
	{
		return 1;
	}

	// recursive case WITH state change towards the base case
	{
		// num--  --->  use value of num THEN num = num - 1
		// --num  --->  num = num - 1 THEN use value of num
		return num * factorial_recursive(--num); 
	}
}

// fibonacci
// f(num) = f(num-2) + f(num-1)
// 0 1 *2* 3 4 5 6
// 0 1 *1* 2 3 5 8 
unsigned int fibonacci_iterative(unsigned int num)
{
	unsigned int twoBack = 0;
	unsigned int oneBack = 1;
	unsigned int current = 0;

	for (unsigned int i = 2; i <= num; i++)
	{
		current = oneBack + twoBack;
		twoBack = oneBack;
		oneBack = current;
	}

	return current;
}

unsigned int fibonacci_recursive(unsigned int num)
{
	// base case -- first TWO terms
	if (num <= 1)
	{
		return num;
	}

	// recursive case with state change
	return fibonacci_recursive(num - 1) + fibonacci_recursive(num - 2);

}

unsigned int fibonacci_recursive_count(unsigned int num, unsigned int& count)
{
	count++;

	// base case -- first TWO terms
	if (num <= 1)
	{
		return num;
	}

	// recursive case with state change
	return fibonacci_recursive_count(num - 1,count) + fibonacci_recursive_count(num - 2,count);

}


unsigned int fibonacci_recursive_cached(unsigned int num, unsigned int* cache, unsigned int& count)
{
	count++;

	// if I know the answer already, return it!
	if (cache[num] != 0 || num == 0)
	{
		return cache[num];
	}

	// base case -- first TWO terms
	if (num <= 1)
	{
		cache[num] = num;
	}
	else
	{
		// recursive case with state change
		cache[num] = fibonacci_recursive_cached(num - 1, cache, count) + fibonacci_recursive_cached(num - 2, cache, count);
	}

	return cache[num];
}