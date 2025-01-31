// RandomDbg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int nextRandInt(int min, int max);
float nextRandFloat();

int main()
{
	cout << rand() << " ";
	for (int i = 0; i < 500; i++)
	{
		cout << rand() << " ";
	}
	cout << endl << endl;

	srand(42); // set a seed
	cout << rand() << " ";
	for (int i = 0; i < 5; i++)
	{
		cout << rand() << " ";
	}
	cout << endl << endl;

	srand(time(NULL)); // set a seed TO SOMETHING THAT CHANGES
	rand(); // sometimes throw away the 1st one
	cout << rand() << " ";
	for (int i = 0; i < 5; i++)
	{
		cout << rand() << " ";
	}
	cout << endl << endl;


	// rand() --> 0 to RAND_MAX
	cout << RAND_MAX << endl;
	cout << nextRandInt(10, 100) << endl;
	cout << nextRandFloat() << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << nextRandInt(10, 100) << " ";
	}
	cout << endl << endl;
}

int nextRandInt(int min, int max)
{
	return (nextRandFloat()) * (max - min) + min;
	//return rand() % (max - min) + min;
}

float nextRandFloat()
{
	return (float)rand() / RAND_MAX;
}

