// Inheritance_part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "Character.h"
#include "Sorcerer.h"

int main()
{
	Character c1;
	c1.PrintData();
	c1.PrintType();
	cout << endl;

	Character c2("Shiro");
	c2.PrintData();
	c2.PrintType();
	cout << endl;

	Sorcerer s1;
	s1.PrintData();
	s1.PrintType();
	cout << endl;

	Character* cPtr = new Sorcerer("Lacy", 100.0f);
	cPtr->PrintData();
	cPtr->PrintType();
	cout << endl;

	delete cPtr;
	cPtr = nullptr;
	cout << endl;
}

