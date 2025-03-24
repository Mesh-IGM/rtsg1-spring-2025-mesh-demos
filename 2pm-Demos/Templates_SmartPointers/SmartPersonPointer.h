#pragma once

#include "Person.h"

// THIS IS A ***BAD*** SMART POINTER

class SmartPersonPointer
{
public:
	SmartPersonPointer(Person* _ptr = nullptr);
	~SmartPersonPointer();

	Person& operator *();
	Person* operator ->();

private:
	Person* ptr;
};

