// OOPDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Pet.h"
#include "Toy.h"
#include "Pigeon.h"

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
	Toy ball;
	//cout << ball.name << endl;
	ball.Print();

	Toy* stick = new Toy("stick", 2.0f);
	stick->Print();
	delete stick;

	Pigeon* pudge = new Pigeon("Pudge", 5, "PUDGE");
	//cout << pudge->name << endl; // private in Pet
	//cout << pudge->numToys << endl; // protected in Pet
	cout << pudge->publicPetField << endl; // public in Pet

	pudge->Print();

	delete pudge;
}