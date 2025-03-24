#include "Person.h"

#include <iostream>
using namespace std;

Person::Person(std::string _name)
{
	cout << "Person() - " << _name << endl;
	name = _name;
}

Person::~Person()
{
	cout << "~Person() - " << name << endl;
}

void Person::print()
{
	cout << "Hi! My name is " << name << endl;
}
