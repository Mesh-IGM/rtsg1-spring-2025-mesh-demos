#pragma once

#include <string>

class Person
{
public:
	Person(std::string _name);
	~Person(); // just so we can have a cout debug

	void print();

private:
	std::string name;
};

