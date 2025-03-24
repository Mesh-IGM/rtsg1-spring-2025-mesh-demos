#include "SmartPersonPointer.h"

#include <iostream>
using namespace std;

SmartPersonPointer::SmartPersonPointer(Person* _ptr)
{
	ptr = _ptr;
	cout << "SmartPersonPointer()" << endl;
}

SmartPersonPointer::~SmartPersonPointer()
{
	cout << "~SmartPersonPointer()" << endl;
	delete ptr;
	ptr = nullptr;
}

Person& SmartPersonPointer::operator*()
{
	return *ptr;
}

Person* SmartPersonPointer::operator->()
{
	return ptr;
}
