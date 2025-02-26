#include "Pet.h"

#include <iostream>
using namespace std;

typedef unsigned short ushort;

Pet::Pet()
{
	cout << "Pet constructor" << endl;
	name = "Binky";
	age = 30;
	numToys = 4;
	toyIds = new ushort[numToys];

	for (ushort i = 0; i < numToys; i++)
	{
		toyIds[i] = rand() % 100;
	}
}

Pet::~Pet()
{
	cout << "~Pet destructor" << endl;
	delete[] toyIds;
	toyIds = nullptr; // not strictly nec
}

void Pet::Print()
{
	cout << "Pet: " << name << endl;

	for (ushort i = 0; i < numToys; i++)
	{
		cout << toyIds[i] << ", ";
	}
	cout << endl;
}
