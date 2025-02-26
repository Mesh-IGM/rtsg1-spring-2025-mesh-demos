#include "Toy.h"

using namespace std;
#include <iostream>

Toy::Toy()
{
	price = 0.0f;
	name = new char[6] {"Shiro"};
}

Toy::Toy(const char* _name, float _price)
{
	this->price = _price;
	unsigned int nameSize = strlen(_name)+1;
	name = new char[nameSize];
	strcpy_s(name, nameSize, _name);
}

Toy::~Toy()
{
	delete[] name;
}

void Toy::Print()
{
	cout << "Pet name: " << name << endl;
}
