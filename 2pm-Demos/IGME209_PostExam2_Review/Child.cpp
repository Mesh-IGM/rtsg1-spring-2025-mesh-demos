#include "Child.h"
#include <iostream>

// DONE: Make this compile
Child::Child(std::string name)
	// : base(name) // C#
	: Parent(name)
{
	std::cout << "Child()"<< std::endl;
	moreData = new int[MORE_DATA_SIZE];
	for (int i = 0; i < MORE_DATA_SIZE; i++)
	{
		moreData[i] = rand() % 10;
	}
}

void Child::Display()
{
	// DONE: Make sure the Parent's data is displayed first
	Parent::Display();
	std::cout << "\tDataSet2: ";
	for (int i = 0; i < MORE_DATA_SIZE; i++)
	{
		std::cout << moreData[i] << " ";
	}
	std::cout << std::endl;
}

Child::~Child()
{
	std::cout << "~Child()" << std::endl;
	delete[] moreData;
}
