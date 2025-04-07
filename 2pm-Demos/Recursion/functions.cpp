#include "functions.h"


// 5! = 1 * 2 * 3 * 4 * 5
unsigned int factorial_for(unsigned int num)
{
	unsigned int product = 1;
	for (int i = 2; i <= num; i++)
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