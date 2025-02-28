#include "Pet.h"

#include <iostream>
using namespace std;

typedef unsigned short ushort;

Pet::Pet()
	: Pet("Binky", 5)
{
}

Pet::Pet(const char* _name, unsigned short _age)
{
	age = _age;
	// name = _name;
	int nameLen = strlen(_name)+1;
	name = new char[nameLen];
	strcpy_s(name, nameLen, _name);

	myFriends = vector<Pet*>();
}

Pet::~Pet()
{
	//cout << "Pet destructor" << endl;
	delete[] name;

	// Do NOT delete the Pet* in friends b/c something else created them!
}

void Pet::AddFriend(Pet* newFriend)
{
	myFriends.push_back(newFriend);
}

char* Pet::GetName()
{
	return name;
}

void Pet::Print()
{
	cout << "\n\nPet: " << name << endl;
	cout << "My friends: ";
	for (int i = 0; i < myFriends.size(); i++)
	{
		cout << myFriends[i]->name << ", ";
	}
	cout << endl;
}
