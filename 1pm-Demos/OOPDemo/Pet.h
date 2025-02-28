#pragma once

#include <string>
#include <vector>
#include "Toy.h"

// class name
struct Pet
{
public:
	// const
	Pet();
	Pet(std::string name, int age);
	~Pet();

	// methods
	virtual void Print();

	int publicPetField;

// data - fields
private:
	std::string name;
	unsigned short age;

protected:
	unsigned short numToys;
	std::vector<Toy*> toys;
};