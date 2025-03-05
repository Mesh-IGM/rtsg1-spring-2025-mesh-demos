#include "Sorcerer.h"

#include <iostream>
using namespace std;

Sorcerer::Sorcerer() : Sorcerer("Gandalf the White", 10)
{
#ifdef DEBUG_ON
	cout << "Sorcerer Default constructor" << endl;
#endif
}

Sorcerer::Sorcerer(std::string _name, int _numSpells)
	: Character(_name)
{
#ifdef DEBUG_ON
	cout << "Sorcerer Param constructor for " << _name << endl;
#endif
	numSpells = _numSpells;
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
	cout << "\tNumber of spells: " << numSpells << endl;
}

void Sorcerer::PrintType()
{
	cout << "\tType: Sorcerer!" << endl;
}
