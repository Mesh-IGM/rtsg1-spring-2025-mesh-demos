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

#include <memory>

Person* normalPtrReview();
void smartPerson();
void customSmartPointers();
void uniquePtrs();
void useUniquePtr(unique_ptr<Person>& param);
void sharedPtrs();
void useSharedPtr(shared_ptr<Person> param);

int main()
{
	sharedPtrs();

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

void customSmartPointers()
{
	//TemplateExample<int> intEx = TemplateExample<int>();
	//TemplateExample<string> strEx = TemplateExample<string>();
	//TemplateExample<Person*> personEx = TemplateExample<Person*>();

	SmartPointer<string> strSP = SmartPointer<string>(new string("Cosmo"));
	SmartPointer<Person> personSP = SmartPointer<Person>(new Person("Moxie"));
	//SmartPointer<Person> otherSP = personSP; // BAD -- shallow copy and then tries to delete twice
}

void uniquePtrs()
{
	unique_ptr<Person> uniquePerson = unique_ptr<Person>(new Person("Cosmo"));
	//unique_ptr<Person> otherPerson = uniquePerson; // NOT ALLOWED
	unique_ptr<Person> newOwner = std::move(uniquePerson);

	Person* a = new Person("Moxie");
	unique_ptr<Person> aSP(a);
	// BAD -- unique ptr will NOT protect me from myself
	//unique_ptr<Person> bSP(a);

	useUniquePtr(aSP);
}

void useUniquePtr(unique_ptr<Person>& param)
{
	param->print();
}

void sharedPtrs()
{
	shared_ptr<Person> sharedPerson(new Person("COSMO"));
	shared_ptr<Person> otherPtr = sharedPerson;
	useSharedPtr(otherPtr);

	Person* a = new Person("Lacy");
	shared_ptr<Person> aPtr(a); // = shared_ptr<Person>(a);
	// BAD -- shared ptr has no way to know the ref count is shared here
	//shared_ptr<Person> bPtr(a);
}

void useSharedPtr(shared_ptr<Person> param) // By value NOT by reference!
{
	param->print();
}