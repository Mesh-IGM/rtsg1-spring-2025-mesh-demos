#include "pch.h"
#include "Vector2.h"
#include <iostream>

SIMPLEMATH_API void Vector2::Print()
{
	std::cout << "Vector: (" << x << ", " << y << ")" << std::endl;
}
