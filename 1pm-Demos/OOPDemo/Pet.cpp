#include "Pet.h"

#include <iostream>
using namespace std;

typedef unsigned short ushort;

Pet::Pet()
	: Pet("Binky", 30)
{
}

Pet::Pet(std::string name, int age)
{
	this->name = name;
	this->age = age;
	numToys = 4;

	toys = vector<Toy*>();

	for (ushort i = 0; i < numToys; i++)
	{
		toys.push_back(new Toy());
	}
	for (ushort i = 0; i < numToys; i++)
	{
		toys[i]->Print();
	}
}

Pet::~Pet()
{
	for (ushort i = 0; i < numToys; i++)
	{
		delete toys[i];
	}
}

void Pet::Print()
{
	cout << "Pet: " << name << endl;

	for (ushort i = 0; i < numToys; i++)
	{
		toys[i]->Print();
	}
}
