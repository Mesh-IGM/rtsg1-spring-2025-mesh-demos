
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