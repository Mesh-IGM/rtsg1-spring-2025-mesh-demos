#include "Multiclass.h"

#include <iostream>
using namespace std;

Multiclass::Multiclass()
{
#ifdef DEBUG_ON
	cout << "Multiclass Default Constructor" << endl;
#endif
}

Multiclass::Multiclass(std::string _name, float _magicPower, std::string _deity)
	: Cleric(_name, _deity), Sorcerer(_name, _magicPower)
{
#ifdef DEBUG_ON
	cout << "Multiclass Param Constructor for " << _name << endl;
#endif
}

Multiclass::~Multiclass()
{
#ifdef DEBUG_ON
	//cout << "Multiclass Destructor for " << name << endl;
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
