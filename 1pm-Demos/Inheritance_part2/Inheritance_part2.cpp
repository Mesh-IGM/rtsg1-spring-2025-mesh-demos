// Inheritance_part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "Character.h"
#include "Sorcerer.h"
#include "Cleric.h"
#include "Multiclass.h"

int main()
{
	/*
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
	
	Sorcerer* sPtr = new Sorcerer("Lacy", 100.0f);
	sPtr->PrintData();
	sPtr->PrintType();
	cout << endl;

	Character* cPtr = sPtr;
	cPtr->PrintData();
	cPtr->PrintType();

	delete cPtr;
	cPtr = nullptr;
	cout << endl;

	Cleric* clPtr = new Cleric();
	clPtr->PrintData();
	clPtr->PrintType();
	delete clPtr;
	*/

	Multiclass mc = Multiclass();
	cout << endl;

	Multiclass* mcPtr = new Multiclass();
	mcPtr->PrintData();
	mcPtr->PrintType();

	Character* cMcPtr = mcPtr;
	cMcPtr->PrintData();
	cMcPtr->PrintType();

	cout << endl;
	delete cMcPtr;
	cout << endl;
}

