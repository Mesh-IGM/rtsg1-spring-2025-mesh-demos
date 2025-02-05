// MorePointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	// Setup
	int myInt = 40;
	int* myIntPtr = &myInt;

	// ONLY need to delete data on the heap
	// delete myIntPtr;

	myIntPtr = nullptr;

	int* heapIntPtr = new int(50); // ptr is on the stack, data on the heap
	delete heapIntPtr;
	heapIntPtr = nullptr;

	// REALLY BAD IDEA
	new int(60);

}
