// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Player.h"

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
	/*
	int a = 5;
	int* bPtr = new int(4);
	delete bPtr;
	bPtr = nullptr;
	*/

	Player p1;
	p1.Print();

	Player* p2Ptr = new Player();
	p2Ptr->Print();
	delete p2Ptr;
	p2Ptr = nullptr;
}

