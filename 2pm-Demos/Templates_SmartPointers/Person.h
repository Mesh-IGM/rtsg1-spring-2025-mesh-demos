#pragma once

#include <string>

class Person
{
public:
	Person(std::string _name);
	~Person(); // just so we can put a cout in it
	void print();

private:
	std::string name;
};

