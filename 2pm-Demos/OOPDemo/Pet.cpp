#include "Pet.h"

#include <iostream>
using namespace std;

typedef unsigned short ushort;

Pet::Pet()
{
	age = 30;
	numFriends = 4;
	name = new char[6] {"Shiro"};
}

Pet::Pet(const char* _name, unsigned short _age, unsigned short _numFriends)
{
	//this->age = age;
	//this->numFriends = numFriends;
	age = _age;
	numFriends = _numFriends;
	// name = _name;
	int nameLen = strlen(_name)+1;
	name = new char[nameLen];
	strcpy_s(name, nameLen, _name);
}

Pet::~Pet()
{
	cout << "Pet destructor" << endl;
	delete[] name;
}

void Pet::Print()
{
	cout << "Pet: " << name << endl;
}
