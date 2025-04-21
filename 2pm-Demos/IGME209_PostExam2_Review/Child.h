#pragma once
#include "Parent.h"

class Child
	: public Parent
{
public:
	Child(std::string name);
	void Display() override;
	// DONE: Add an appropriate destructor here & implement it in Child.cpp
	~Child();

// Fields are correct. You may NOT change them or their access level!
private:
	int* moreData;
	const int MORE_DATA_SIZE = 5;

};

