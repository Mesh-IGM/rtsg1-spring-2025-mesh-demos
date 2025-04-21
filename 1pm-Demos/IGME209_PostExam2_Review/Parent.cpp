#include "Parent.h"
#include <iostream>

Parent::Parent(std::string name)
{
	std::cout << "Parent()" << std::endl;
	this->name = name;
	data = new int[DATA_SIZE];
	for (int i = 0; i < DATA_SIZE; i++)
	{
		data[i] = rand() % 10;
	}
}

void Parent::Display()
{
	std::cout << name << ": "<< std::endl;
	std::cout << "\tDataSet1: ";
	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}


Parent::~Parent()
{
	std::cout << "~Parent()" << std::endl;
	delete[] data;
}