// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void doBadStuff();

void passByValue(short x);

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

	// infinitely call a method and hope it cleans up after itself :(
//	while (true)
//	{
		doBadStuff();
//	}

		cout << endl;


		// ** Pass by value **
		passByValue(myShort);
		cout << myShort << endl;

		// same as
		short x = myShort;
		x = 100;
		cout << myShort << endl;


}

void passByValue(short x)
{
	cout << "pBV: "<< x << endl;
	x = 100;
	cout << "pBV: " << x << endl;
}

void doBadStuff()
{
	int* intPtr = new int(100);
	// do whatever with my data
	cout << intPtr << endl;
	cout << *intPtr << endl;
	delete intPtr; // doesn't delete the ptr. Deletes & reclaims the data memory
	intPtr = nullptr;
	//cout << intPtr << endl;
	//cout << *intPtr << endl;

}

