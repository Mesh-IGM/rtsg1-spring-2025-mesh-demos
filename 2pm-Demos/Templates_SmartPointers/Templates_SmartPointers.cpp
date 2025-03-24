// Templates_SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Person.h"
#include "SmartPersonPointer.h"
#include "TemplateExample.h"
#include "SmartPointer.h"

Person* normalPtrReview();
void smartPerson();
void smartPointers();

int main()
{
	smartPointers();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS?!" << endl;
	else
		cout << "\nNo leaks :)" << endl;
}

Person* normalPtrReview()
{
	Person pStack = Person("Shiro");
	Person* pHeapPtr = new Person("Lacy");

	pStack.print();
	pHeapPtr->print();
	//delete pHeapPtr;

	return pHeapPtr;
}

void smartPerson()
{
	SmartPersonPointer p = SmartPersonPointer(new Person("Lacy"));
	p->print();
}

void smartPointers()
{
	TemplateExample<int> intEx = TemplateExample<int>();
	TemplateExample<string> strEx = TemplateExample<string>();
	TemplateExample<Person*> personEx = TemplateExample<Person*>();

	//SmartPointer<string> strSP = SmartPointer<string>(new string("Cosmo"));
}
