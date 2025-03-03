#pragma once

#include <string>

#define DEBUG_ON

class Character
{
public:
	Character();
	Character(std::string _name);

	virtual ~Character(); // technically don't need this

	virtual void PrintData();
	/*virtual*/ void PrintType();

	std::string name;
};

