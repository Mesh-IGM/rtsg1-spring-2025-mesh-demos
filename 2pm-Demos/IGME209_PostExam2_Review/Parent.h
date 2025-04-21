#pragma once

#include <string>

class Parent
{
public:
	Parent(std::string name);
	virtual void Display();
	// DONE: Add an appropriate destructor here & implement it in Parent.cpp
	virtual ~Parent();

// Fields are correct. You may NOT change them or their access level!
private:
	std::string name;
	int* data;
	const int DATA_SIZE = 3;

};

