// Templates_SmartPtrs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <memory>
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
void customSmartPointer();
void uniquePtrs();
void useUniquePtr(unique_ptr<Person>& param);
void sharedPtrs();
void useSharedPtr(shared_ptr<Person> param);

int main()
{
	//normalPtrReview();
	//smartPerson();
	//customSmartPointer();
	//uniquePtrs();
	sharedPtrs();

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

void customSmartPointer()
{
	//TemplateExample<int> intEx = TemplateExample<int>();
	//TemplateExample<string> stringEx = TemplateExample<string>();
	//TemplateExample<Person*> personPtrEx = TemplateExample<Person*>();

	SmartPointer<string> stringSP = SmartPointer<string>(new string("Cosmo"));
	SmartPointer<Person> personSP = SmartPointer<Person>(new Person("Moxie"));

}

void uniquePtrs()
{
	unique_ptr<Person> uniquePerson(new Person("Cosmo"));
	unique_ptr<Person> newOwner = std::move(uniquePerson);
	// NOT ALLOWED - unique_ptr<Person> otherPerson = uniquePerson;

	useUniquePtr(newOwner);

	Person* a = new Person("sdfsd");
	Person* b = a;
	unique_ptr<Person> aSP = unique_ptr<Person>(a);
	// BAD IDEA - unique ptr can't protect us from ourselves!
	// unique_ptr<Person> bSP = unique_ptr<Person>(b);
}

// MUST pass by reference
void useUniquePtr(unique_ptr<Person>& param)
{
	param->print();
}

void sharedPtrs()
{
	shared_ptr<Person> sharedPerson(new Person("Cosmo")); // 1
	shared_ptr<Person> otherPtr = sharedPerson; // 2
	useSharedPtr(otherPtr);

	Person* a = new Person("sdfsd");
	shared_ptr<Person> aSP = shared_ptr<Person>(a);
	// BAD IDEA - shared ptr can't ref count without knowing it was a copy
	// shared_ptr<Person> bSP = shared_ptr<Person>(a);


} // last 2 go out of scope --> 2 --> 1 --> 0

void useSharedPtr(shared_ptr<Person> param) // 3 
{
	param->print();
} // 2
