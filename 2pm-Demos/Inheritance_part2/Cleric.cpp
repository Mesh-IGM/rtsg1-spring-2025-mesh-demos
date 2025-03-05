#include "Cleric.h"

#include <iostream>
using namespace std;

Cleric::Cleric() : Cleric("Aiden", "Peanuts")
{
#ifdef DEBUG_ON
	cout << "Cleric Default constructor" << endl;
#endif
}

Cleric::Cleric(std::string _name, std::string _deity)
	: Character(_name)
{
#ifdef DEBUG_ON
	cout << "Cleric Param constructor for " << _name << endl;
#endif
	deity = _deity;
}

Cleric::~Cleric()
{
#ifdef DEBUG_ON
	cout << "Cleric Destructor for " << name << endl;
#endif
}

void Cleric::PrintData()
{
	Character::PrintData();
	cout << "\tDeity: " << deity << endl;
}

void Cleric::PrintType()
{
	cout << "\tType: Cleric!" << endl;
}
