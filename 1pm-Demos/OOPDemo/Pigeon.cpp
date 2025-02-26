#include "Pigeon.h"

using namespace std;
#include <iostream>

Pigeon::Pigeon()
{
	nickname = "PUDGE";
}

Pigeon::Pigeon(std::string name, int age, std::string nickname)
	: Pet(name, age)
{
	this->nickname = nickname;
	//this->name = name;
}

Pigeon::~Pigeon()
{
}

void Pigeon::Print()
{
	Pet::Print();
	cout << "Nickname: " << nickname << endl;
}

void Pigeon::Fly()
{
}
