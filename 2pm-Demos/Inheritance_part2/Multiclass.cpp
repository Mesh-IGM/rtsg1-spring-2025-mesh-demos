#include "Multiclass.h"

#include <iostream>
using namespace std;

Multiclass::Multiclass() 
{
#ifdef DEBUG_ON
	cout << "Multiclass Default constructor" << endl;
#endif
}

Multiclass::Multiclass(std::string _name, int _numSpells, std::string _deity)
	: Sorcerer(_name, _numSpells), Cleric(_name, _deity)
{
#ifdef DEBUG_ON
	cout << "Multiclass Param constructor for " << _name << endl;
#endif
}

Multiclass::~Multiclass()
{
#ifdef DEBUG_ON
	cout << "Multiclass Destructor for " << name << endl;
#endif
}

void Multiclass::PrintData()
{
	Sorcerer::PrintData();
	cout << "\tDeity: " << deity << endl;
}

void Multiclass::PrintType()
{
	cout << "\tType: Multiclass!" << endl;
}
