// MorePointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

void origMain();

void arrPtrDemos(int arrSize);

int main()
{
	// origMain();
	arrPtrDemos(5);

	if (_CrtDumpMemoryLeaks())
	{
		cout << "MEMORY LEAK! - CHECK DEBUG OUTPUT!!" << endl;
	}
}

void arrPtrDemos(int arrSize)
{
	// int myArray[arrSize]; // :(
	int* arrPtr = new int[arrSize] {}; // ptr on the stack, data on the heap


	for (int i = 0; i < arrSize; i++)
	{
		arrPtr[i] = i + 1;
		// same as
		// *(arrPtr + i) = i + 1;
		cout << arrPtr[i] << ", ";
	}
	cout << endl;

	// *(arrPtr + i) ---> arrPtr[i]
	// *(arrPtr + 0) ---> arrPtr[0]

	// resize array: new one, copy, delete, reasign, update size
	int* tmpArr = new int[arrSize * 2] {};
	for (int i = 0; i < arrSize; i++)
	{
		tmpArr[i] = arrPtr[i];
	}

	delete[] arrPtr;

	arrPtr = tmpArr;
	tmpArr = nullptr;
	arrSize *= 2;

	for (int i = 0; i < arrSize; i++)
	{
		cout << arrPtr[i] * arrPtr[i] * arrPtr[i] * arrPtr[i] << ", ";
	}
	cout << endl;

	//int* endArr = arrPtr + arrSize;
	for (int* i = arrPtr, * endArr = arrPtr + arrSize;
		i < endArr; 
		i++)
	{
		cout << *i << " - ";
	}
	cout << endl;

	delete[] arrPtr;
}

void origMain()
{
	int myInt = 40; // on the stack
	int* myIntPtr = &myInt;

	// ONLY need to delete if the data is on the heap
	// delete myIntPtr;

	// we CAN null out a ptr
	myIntPtr = nullptr;

	int* heapIntPtr = new int(60); // ptr is on the stack, data is on the heap
	int* otherPtr = heapIntPtr;
	delete heapIntPtr;
	heapIntPtr = nullptr;

	// otherPtr is now a: dangling ptr
	otherPtr = nullptr;

	new int(70); // instant memory leak

	// Mem leak on purpose
	int* extraPtr = new int(100);
	delete extraPtr;

	// false positive
	string test = "Hello world!";
}
