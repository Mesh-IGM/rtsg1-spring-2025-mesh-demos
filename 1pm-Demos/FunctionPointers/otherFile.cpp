#include "otherFile.h"
#include <iostream>

void runThing(twoNumsFunc thing, int a, int b)
{
	std::cout << "Running thing: " ;
	thing(a, b);
}