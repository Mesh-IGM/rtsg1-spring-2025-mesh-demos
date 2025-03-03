// Inheritance_part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "Character.h"
#include "Sorcerer.h"

int main()
{
	Character c1 = Character();
	c1.PrintData();
	c1.PrintType();
	cout << endl;

	Character c2 = Character("Cosmo");
	c2.PrintData();
	c2.PrintType();
	cout << endl;

	Character* cPtr = new Character("Aiden");
	cPtr->PrintData();
	cPtr->PrintType();
	cout << endl;

	Sorcerer s1 = Sorcerer();
	s1.PrintData();
	s1.PrintType();
	cout << endl;

	Sorcerer s2 = Sorcerer("Moxie", 10);
	s2.PrintData();
	s2.PrintType();
	cout << endl;

	Sorcerer* sPtr = new Sorcerer("Pax", 5);
	sPtr->PrintData();
	sPtr->PrintType();
	cout << endl;

	Character* cPtrToSorcerer = sPtr;
	cPtrToSorcerer->PrintData();
	cPtrToSorcerer->PrintType();
	cout << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	delete cPtr;
	delete cPtrToSorcerer;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
