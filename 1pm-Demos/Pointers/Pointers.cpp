// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void passByValue(short x);

void passByPointer(short* xPtr);

void passByReference(short& xRef);

int main()
{
	short myShort = 10; // local var with data in the heap
	cout << myShort << endl;

	short* myShortPointer = new short(20); // stack pointer to short data in the heap
	cout << myShortPointer << endl;
	cout << *myShortPointer << endl;  // * deref: get me the data at this addr

	myShortPointer = &myShort; // & ref: get me the addr of this data
	cout << *myShortPointer << endl << endl;  

	passByValue(myShort);
	cout << "Pass by value: "<< myShort << endl;

	// same as
	short x = myShort;
	x = 100;
	cout << myShort << endl;

	passByPointer(&myShort);
	cout << "Pass by pointer: " << myShort << endl;

	passByReference(myShort);
    cout << "Pass by ref: " << myShort << endl;

	int myArray[5];
	int* arr0 = &myArray[0];
	int* arr1 = &myArray[1];
	int* arr2 = &myArray[2];

	cout << "arr0: " << arr0 << endl;
	cout << "arr1: " << arr1 << endl;
	cout << "arr2: " << arr2 << endl;

	arr0 += 2; // addr += 2 * sizeof(int)
	cout << "arr0: " << arr0 << endl;

	// For demo only - still do NOT use string for HW1
	// After HW1, go for it unless we require cstrings

	string myString = "Hello";

	// Call a method - same as C#
	myString.pop_back(); // removes a letter from the end

	string* myStrPtr = &myString;

	// calling a method ona ptr... not the same
	// myStrPtr.pop_back();
	(*myStrPtr).pop_back(); // lots of typing
	myStrPtr->pop_back(); // same thing


	/* Run forever to play with memory leaks
	int* myInt = nullptr;
	while (true)
	{
		myInt = new int(30);
		delete myInt; // deletes the data pointed to - without this, memory leak
		// cout << *myInt << endl; // access violation
		myInt = nullptr; // without this -- dangling pointer
	}
	*/
}

void passByValue(short x)
{
	x = 100;
}

void passByPointer(short* xPtr)
{
	*xPtr = 200;
	// BAD
	//xPtr = new short(200);
}

void passByReference(short& xRef)
{
	xRef = 300;
}
