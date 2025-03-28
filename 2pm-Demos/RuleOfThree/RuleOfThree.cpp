// RuleOfThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
using namespace std;

#include "Player.h"

void wrapper();

int main()
{
	wrapper();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS?!" << endl;
	else
		cout << "\nNo leaks :) " << endl;
}

void wrapper()
{
	// test the base setup
	Player myPlayer = Player(1, 2, 3); // NEW - a
	myPlayer.print();
	myPlayer.swap(1, 4);
	myPlayer.print();

	// * 1 * --- even an obj on the stack can point to mem on the heap

	// * 2 *
	cout << endl;
	Player otherPlayer = Player(myPlayer); // NEW - b
	otherPlayer.print();
	otherPlayer.swap(1, 99);
	otherPlayer.print();
	myPlayer.print();

	// * 3 *
	cout << endl;
	myPlayer = otherPlayer; // NEW - c ---- loses track of a
	otherPlayer.print();
	myPlayer.print();

	// * 3a *
	cout << endl;
	myPlayer = myPlayer;
	myPlayer.print();

	// keep in mind
	Player* p1 = new Player(1, 2, 3);
	//Player* p2 = p1; // ptr copy, not deep copy
	//Player p2 = p1; // bad
	Player p2 = *p1; // Player(*p1);

	Player* p3 = new Player(6, 7, 8);
	//p1 = p3; // copy ptr -- create a dangling ptr
	*p1 = *p3;

	delete p1;
	delete p3;


	// let things go out of scope
	cout << endl;
}