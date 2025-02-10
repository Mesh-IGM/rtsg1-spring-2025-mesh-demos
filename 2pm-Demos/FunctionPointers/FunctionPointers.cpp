// FunctionPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;
#include "otherFile.h"

typedef unsigned int uint;
typedef void(*intFuncPtr)(int);

void helloWorld(int n);
void square(int n);


void addTwoNumbers(int a, int b);
void printTwoNumbers(int a, int b);

bool descending(int a, int b);

int main()
{
	// pointers recap
	int myInt = 5;
	myInt;
	int* myIntPtr = &myInt;
	myIntPtr;
	cout << myIntPtr << endl;
	int* otherIntPtr = new int(6);
	cout << endl;

	helloWorld(5);
	helloWorld;
	cout << helloWorld << endl;

	// function pointer variable declaration
	// return type(* varName)(param type)
	void(*helloFuncPtr)(int);
	
	// init/assign
	helloFuncPtr = helloWorld;
	cout << helloFuncPtr << endl;
	helloFuncPtr(10);

	// typedefs
	uint test = 4;
	intFuncPtr myFunc = square;
	myFunc(8);
	myFunc = helloWorld;
	myFunc(8);

	// let the user pick what to do
	int choice = 0;
	twoNumFunc thing;
	cout << "0: add, 1: print" << endl;
	//cin >> choice;
	if (choice) // 0 is false
	{
		thing = printTwoNumbers;
	}
	else
	{
		thing = addTwoNumbers;
	}
	thing(20, 40);
	runThing(addTwoNumbers, 10, 20);
	runThing(printTwoNumbers, 10, 20);
	runThing(thing, 30, 40);

	//
	const uint ARR_SIZE = 5;
	int intArray[ARR_SIZE] = {6, 1, 9, 3, 8};
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

	std::sort(
		intArray, 
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
	// true == a goes on the left
	// we want bigger on the left
	return a > b;
}

void helloWorld(int n)
{
	cout << "Hello " << n << endl;
}

void square(int n)
{
	cout << "square of " << n << " is " << n * n << endl;
}

void addTwoNumbers(int a, int b)
{
	cout << a + b << endl;
}

void printTwoNumbers(int a, int b)
{
	cout << a << ", " << b << endl;
}
