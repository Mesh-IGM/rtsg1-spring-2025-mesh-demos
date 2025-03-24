// Templates_SmartPtrs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Person.h"
#include "SmartPersonPointer.h"
#include "TemplateExample.h"

Person* normalPtrReview();
void smartPerson();
void smartPointer();

int main()
{
	//normalPtrReview();
	//smartPerson();
	smartPointer();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS?!" << endl;
	else
		cout << "\nNo leaks :) " << endl;

}

Person* normalPtrReview()
{
	Person a = Person("Shiro");
	a.print();

	Person* b = new Person("Lacy");
	b->print();

	return b;
}

void smartPerson()
{
	SmartPersonPointer sp = SmartPersonPointer(new Person("Lacy"));
	sp->print();
}

void smartPointer()
{
//	SmartPointer<string> stringSP = SmartPointer<string>(new string("Cosmo"));

	TemplateExample<int> intEx = TemplateExample<int>();
	TemplateExample<string> stringEx = TemplateExample<string>();
	TemplateExample<Person*> personPtrEx = TemplateExample<Person*>();
}
