#include "Sorcerer.h"

#include <iostream>
using namespace std;

Sorcerer::Sorcerer() : Sorcerer("Gandalf", 70.0f)
{
#ifdef DEBUG_ON
	cout << "Sorcerer Default Constructor" << endl;
#endif
}

Sorcerer::Sorcerer(std::string _name, float _magicPower)
	: Character(_name)
{
#ifdef DEBUG_ON
	cout << "Sorcerer Param Constructor for " << _name << endl;
#endif
	magicPower = _magicPower;
}

Sorcerer::~Sorcerer()
{
#ifdef DEBUG_ON
	cout << "Sorcerer Destructor for " << name << endl;
#endif
}

void Sorcerer::PrintData()
{
	Character::PrintData();
	cout << "\tMagic Power: " << magicPower << endl;
}

void Sorcerer::PrintType()
{
	cout << "\tType: Sorcerer!" << endl;
}
