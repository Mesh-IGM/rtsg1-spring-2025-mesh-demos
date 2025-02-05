// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void doBadStuff();

void passByValue(short x);

void passByPointer(short* xPtr);

void passByReference(short& xRef);

int main()
{
	short myShort = 10;
	cout << myShort << endl;

	short* myShortPtr = new short(20); // * -- create ptr type ----- new --> on the heap
	cout << myShortPtr << endl;
	cout << *myShortPtr << endl; // * - deref: get me the data at this addr

	delete myShortPtr; // delete/reclaim the memory pointed to
	// without this --> memory leak

	myShortPtr = nullptr; // Reset the ptr to null (without this, dangling ptr)

	myShortPtr = &myShort; // & -- ref: get the addr of this data
	cout << *myShortPtr << endl << endl;

	// ** Pass by value **
	passByValue(myShort); // expecting short
	cout << "Pass by value: "<< myShort << endl;

	// same as
	short x = myShort;
	x = 100;
	cout << myShort << endl;

	passByPointer(&myShort); // expecting short*
	cout << "Pass by pointer: " << myShort << endl;

	passByReference(myShort); // expecting short&
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

	arr0 = &myArray[0];
	for (int i = 0; i < 5; i++)
	{
		cout << *arr0 << endl;
		arr0 += 1;
	}

	// string class in demo -- do NOT use for HW1
	// After HW1, go for it unless we specifically require cstrings

	string myString = "Hello";

	// Calling a method on an obj -- same as C#
	myString.pop_back();

	string* myStrPtr = &myString;
	// myStrPtr.pop_back(); // bad
	(*myStrPtr).pop_back();
	myStrPtr->pop_back();



	// infinitely call a method and hope it cleans up after itself :(
	//while (true)
	{
		doBadStuff();
	}
	cout << endl;
}

void passByValue(short x)
{
	cout << "pBV: " << x << endl;
	x = 100;
	cout << "pBV: " << x << endl;
}

void passByPointer(short* xPtr)
{
	*xPtr = 200;
}

void passByReference(short& xRef)
{
	xRef = 300;
}

void doBadStuff()
{
	int* intPtr = new int(100);
	// do whatever with my data
	//cout << intPtr << endl;
	//cout << *intPtr << endl;
	// NEED THIS delete intPtr; // doesn't delete the ptr. Deletes & reclaims the data memory
	intPtr = nullptr;
	//cout << intPtr << endl;
	//cout << *intPtr << endl;

}

