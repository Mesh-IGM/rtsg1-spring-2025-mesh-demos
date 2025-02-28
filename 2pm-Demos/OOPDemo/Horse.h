#pragma once

#include "Pet.h"

class Horse
	: public Pet
{
public:
	Horse();
	Horse(const char* name, unsigned short age, float maxSpeed);
	void Print() override;

private:
	float maxSpeed;

};

