// FunctionPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "otherFile.h"
using namespace std;

typedef unsigned int uint;
typedef void(*intFuncPtr)(int);

void helloWorld(int num);
void square(int num);

void printTwoNumbers(int a, int b);
void addTwoNumbers(int a, int b);

bool descending(int a, int b);

int main()
{
	int myInt = 5;
	int* myIntPtr = &myInt;
	myIntPtr;
	myInt;
	int* otherIntPtr = new int(5);

	helloWorld(5);
	helloWorld;
	cout << helloWorld << endl;

	// Function ptr var declaration - matches signature
	// return type(* id name)(param types)
	void(*helloPtr)(int);

	// assignment
	helloPtr = helloWorld;

	helloPtr(10);

	// typedefs
	uint test = 3;
	intFuncPtr myFunc = helloWorld;
	myFunc(20);

	myFunc = square;
	myFunc(20);

	// swap out at runtime
	cout << "0: print, 1: add" << endl;
	int choice = 0;
	twoNumsFunc thingToRun;
	//cin >> choice;
	if (choice == 0)
	{
		thingToRun = printTwoNumbers;
	}
	else
	{
		thingToRun = addTwoNumbers;
	}
	thingToRun(20, 40);

	runThing(printTwoNumbers, 1, 2);
	runThing(addTwoNumbers, 1, 2);

	// setup an array
	const uint ARR_SIZE = 5;
	int intArray[ARR_SIZE] = { 6, 4, 2, 7, 1 };
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << intArray[i] << ", ";
	}
	cout << endl;

	std::sort(intArray, intArray + ARR_SIZE);
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << intArray[i] << ", ";
	}
	cout << endl;

	std::sort(intArray, 
		intArray + ARR_SIZE, 
		descending /*predicate function*/);
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << intArray[i] << ", ";
	}
	cout << endl;
}

bool descending(int a, int b)
{
	// true == a goes left of b
	// I want bigger to the left
	return a > b;
}


void helloWorld(int num)
{
	cout << "Hello " << num << endl;
}

void square(int num)
{
	cout << "square of " << num << " is " << num * num << endl;
}

void printTwoNumbers(int a, int b)
{
	cout << "a: " << a << ", b: " << b << endl;
}

void addTwoNumbers(int a, int b)
{
	cout << "a + b: " << a + b << endl;
}
