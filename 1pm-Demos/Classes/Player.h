#pragma once

#include <string>

// name the type
class Player
{
	//private std::string thing;
	//protected std::string thing2;

public:
	// const
	Player();

	// destructor
	~Player();

	// methods (print)
	void Print();

// block scope
private:
	// fields
	std::string name;
	unsigned short invSize;
	short* inventory;
};
