// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void passByValue(short x);

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
	cout << myShort << endl;

	// same as
	short x = myShort;
	x = 100;
	cout << myShort << endl;

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
