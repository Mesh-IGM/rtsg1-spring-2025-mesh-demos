// MorePointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// in iostream too, but good to know in case we aren't using iostream
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

void main_orig();

void arrPtrDemo();

int main()
{
	arrPtrDemo();

	if (_CrtDumpMemoryLeaks())
	{
		cout << "MEMORY LEAKS - CHECK DEBUG OUTPUT WINDOW!" << endl;
	}

}

void main_orig()
{
	// Setup
	int myInt = 40; // on the stack
	int* myIntPtr = &myInt;

	// Only need to delete if on the heap
	// delete myIntPtr;  // --> error pops up in the code for deletion. Doesn't mean the problem is actually there. It isn't
							// Use the call stack to find the 1st thing that YOU wrote

	myIntPtr = nullptr; // This is okay (and good) because it's not deleting anything. 

	int* heapIntPtr = new int(50); // Ptr is on the stack; The DATA is on the heap
	int* otherPtr = heapIntPtr; // ***

	// instant memory leak
	// new int(60); 

	cout << *heapIntPtr << endl; // Dereference the pointer to get the value
	*heapIntPtr = 70; // Change the value of the data on the heap
	cout << *heapIntPtr << endl;

	// We are NOT responsible for deleting every pointer.
	// We are responsible for deleting all data we allocate on the heap.

	delete heapIntPtr; // This deletes the data on the heap
	// Now we have dangling pointers

	// Reset to mem addr 0 so we can check against it and no the pointer is "empty"
	heapIntPtr = nullptr; // If it's going to immediately go out of scope, sometimes we skip this. 
	otherPtr = nullptr; // ***
	// Safer to do it if unsure.

	// Detecting memory leaks -- you are expected to use this from now on!!!
	int* extraPtr = new int(80);
	delete extraPtr;

	_CrtDumpMemoryLeaks(); // DETECTS memory leaks. Doesn't fix them! -- dumps to the debug output window!

	// Doesn't work perfectly - false positive b/c of how string works
	string test = "Hello world";    // under the hood, uses the heap for its underlying data so it can rearrange data as needed
	// It'll get cleaned up when test goes out of scope, but _CrtDumpMemoryLeaks doesn't know that

// To get something in the console: (in non-production code)
	if (_CrtDumpMemoryLeaks())
	{
		cout << "MEMORY LEAKS - CHECK DEBUG OUTPUT WINDOW!" << endl;
	}
}

// Put everything but our memory leak check in a function and call it from main
void arrPtrDemo()
{
	int arrSize = 5;

	// can't compile because arrSize is not a constant & the stack has to be fixed size determined at compile time
	// int myArray[arrSize];

	// Put the array data on the heap instead - fixed size once created
	int* arrPtr = new int[arrSize] { 10, 20, 30, 40, 50 };

	// [i] work on the array ptrs too!
	// it's shorthand for:  *(arrPtr + i)
	for (int i = 0; i < arrSize; i++)
	{
		cout << arrPtr[i] << ", ";
		// same as:
		// cout << *(arrPtr + i) << ", ";
		// This is why arrays index by 0: index == offset from the start of the array (# of elements to skip
	}
	cout << endl;

	// How do I make the array bigger? - can't just add to it b/c there may be more data after it
	// 1. Create a new array
	int* tmpArr = new int[arrSize * 2] {};

	// 2. Copy the data from the old array to the new array
	for (int i = 0; i < arrSize; i++)
	{
		tmpArr[i] = arrPtr[i];
	}

	// 3. Delete the old array -- delete the full array block, not just the first element at the addr
	delete[] arrPtr;

	// 4. Update the pointer to point to the new array
	arrPtr = tmpArr;

	// 5. Update the size of the array
	arrSize *= 2;



	// Other ways to iterate through an array
	//  [] requires a few pointer calcs each time. If we're doing it a lot, it can add up

	int* endArr = arrPtr + arrSize; // byte after the end of the array
	for (int* i = arrPtr; i < endArr; i++)
	{
		cout << *i << "- ";
	}
	cout << endl;

	// endArr is only for the loop. Would rather it were scoped to the loop
	for (int* i = arrPtr, *endArr2 = arrPtr + arrSize;
		i < endArr2;
		i++)
	{
		cout << *i << "* ";
	}
	cout << endl;


	delete[] arrPtr;
}