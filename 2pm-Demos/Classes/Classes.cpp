// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

#include "Pet.h"

void wrapper();

int main()
{
	wrapper();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS!" << endl;
	else
		cout << "\nNo memory leaks. :)" << endl;
}

void wrapper()
{
	Pet binky;
	binky.Print();

	Pet* binkyPtr = new Pet();
	binkyPtr->Print();
	delete binkyPtr;
	binkyPtr = nullptr;
}
