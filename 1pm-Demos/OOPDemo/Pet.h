#pragma once

#include <string>

// class name
class Pet
{
public:
	// const
	Pet();
	~Pet();

	// methods
	void Print();

// data - fields
private:
	std::string name;
	unsigned short age;
	unsigned short numToys;
	unsigned short* toyIds;

};