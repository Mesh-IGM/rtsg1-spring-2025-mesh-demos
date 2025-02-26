#pragma once

#include "Pet.h"

class Horse
	: public Pet
{
public:
	Horse();
	Horse(const char* name, unsigned short age, unsigned short numFriends, float maxSpeed);
	void Print() override;

private:
	float maxSpeed;

};

