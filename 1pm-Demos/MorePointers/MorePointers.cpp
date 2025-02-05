// MorePointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int myInt = 40; // on the stack
	int* myIntPtr = &myInt;

	// ONLY need to delete if the data is on the heap
	// delete myIntPtr;

	// we CAN null out a ptr
	myIntPtr = nullptr;

	int* heapIntPtr = new int(60); // ptr is on the stack, data is on the heap
	delete heapIntPtr;
	heapIntPtr = nullptr;

	new int(70); // instant memory leak


}
