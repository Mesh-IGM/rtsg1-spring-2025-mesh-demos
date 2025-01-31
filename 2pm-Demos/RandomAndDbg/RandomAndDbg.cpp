// RandomAndDbg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float nextDouble();
float nextDouble(float min, float max);
int nextInt(int min, int max);

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << rand() << " ";
	}
	cout << endl;

	srand(42);
	for (int i = 0; i < 5; i++)
	{
		cout << rand() << " ";
	}
	cout << endl;

	srand(time(NULL));
	rand();
	for (int i = 0; i < 5; i++)
	{
		cout << rand() << " ";
	}
	cout << endl;

	cout << "RAND_MAX: " << RAND_MAX << endl;

	for (int i = 0; i < 500; i++)
	{
		cout << nextDouble() << " ";
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << nextDouble(10, 100) << " ";
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << nextInt(10, 100) << " ";
	}
	cout << endl;

}

float nextDouble()
{
	return (float)rand() / RAND_MAX;
}

float nextDouble(float min, float max)
{
	return (max-min)*nextDouble() + min;
}

int nextInt(int min, int max)
{
	//return nextDouble() * (max - min) + min;
	return rand() % (max - min) + min;
}
