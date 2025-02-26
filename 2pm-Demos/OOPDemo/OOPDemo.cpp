// OOPDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Pet.h"
#include "Toy.h"
#include "Horse.h"


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
	Pet* shiro = new Pet("Shiro", 7, 5);
	//cout << shiro->age << endl;
	delete shiro;

	//Toy stick;
	//cout << stick.price << endl;

	Horse aiden;
	//cout << aiden.name << endl; // private in Pet
	//cout << aiden.numFriends << endl; // protected in Pet
	cout << aiden.publicPetField << endl; // public in Pet

	Horse* cosmo = new Horse("Cosmo", 5, 100, 5);
	cosmo->Print();
	delete cosmo;
}