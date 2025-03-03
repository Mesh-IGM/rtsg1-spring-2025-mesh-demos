#include "Character.h"

#include <iostream>
using namespace std;

Character::Character() : Character("Bob")
{
#ifdef DEBUG_ON
	cout << "Default Constructor" << endl;
#endif
}

Character::Character(std::string _name)
{
#ifdef DEBUG_ON
	cout << "Param Constructor for " << _name << endl;
#endif
	name = _name;
}

Character::~Character()
{
#ifdef DEBUG_ON
	cout << "Destructor for " << name << endl;
#endif
}

void Character::PrintData()
{
	cout << name << endl;
}

void Character::PrintType()
{
	cout << "\tType: Character!" << endl;
}
