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
	// Base demo setup
	Player myPlayer(1, 2, 3); // NEW -- a
	myPlayer.printInventory();
	myPlayer.swapItem(1, 4);
	myPlayer.printInventory();

	// * #1 * -- obj on the stack but has memory on the heap!

	// * #2 *
	cout << endl;
	Player otherPlayer = myPlayer; // NEW -- b
	//Player otherPlayer = Player(otherPlayer);
	otherPlayer.swapItem(1, 99);
	otherPlayer.printInventory();
	myPlayer.printInventory();

	// * #3 *
	cout << endl;
	myPlayer = otherPlayer; // NEW -- c ---- lose a
	otherPlayer.printInventory();
	myPlayer.printInventory();


	// * 3a*
	cout << endl;
	otherPlayer = otherPlayer;
	otherPlayer.printInventory();


	// other gotchas
	Player* p1 = new Player(5, 6, 7);
	//Player p2 = p1;
	//Player* p2 = p1; // 2 pointers
	Player p2 = Player(*p1);

	Player* p3 = new Player(8, 9, 0);
	//p1 = p3;
	*p1 = *p3;

	delete p1;
	delete p3;

	// Let things go out of scope
	cout << endl;
}