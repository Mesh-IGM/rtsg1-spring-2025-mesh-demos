#include "Horse.h"

#include <iostream>
using namespace std;

Horse::Horse()
{
	maxSpeed = 10.0f;
}

Horse::Horse(const char* name, unsigned short age, float maxSpeed)
	: Pet(name, age)
{
	this->maxSpeed = maxSpeed;
}

void Horse::Print()
{
	//cout << name << endl; // private in Pet
	//cout << numFriends << endl; // protected in Pet
	//cout << publicPetField << endl; // public in Pet
	Pet::Print();
	cout << "Max speed: " << maxSpeed << endl;
}
