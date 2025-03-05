#include "Character.h"

#include <iostream>
using namespace std;

Character::Character() : Character("Gandalf")
{
#ifdef DEBUG_ON
	cout << "Character Default constructor" << endl;
#endif
}

Character::Character(std::string _name)
{
#ifdef DEBUG_ON
	cout << "Character Param constructor for " << _name << endl;
#endif
	name = _name;
}

Character::~Character()
{
#ifdef DEBUG_ON
	cout << "Character Destructor for " << name << endl;
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
