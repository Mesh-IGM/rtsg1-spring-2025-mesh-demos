#include "Person.h"

using namespace std;
#include <iostream>

Person::Person(std::string _name)
{
	name = _name;
	cout << "Person() - " << name << endl;
}

Person::~Person()
{
	cout << "~Person() - " << name << endl;
}

void Person::print()
{
	cout << "Hi! My name is " << name << "!" << endl;
}
