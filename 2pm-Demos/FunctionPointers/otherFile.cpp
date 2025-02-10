#include "otherFile.h"
#include <iostream>
void runThing(twoNumFunc thing, int a, int b)
{
	std::cout << "running: ";
	thing(a, b);
	// addTwoNumber(1, 2);
}