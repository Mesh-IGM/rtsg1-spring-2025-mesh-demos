#pragma once

#ifdef SIMPLEMATH_EXPORTS
	#define SIMPLEMATH_API __declspec(dllexport)
#else
	#define SIMPLEMATH_API __declspec(dllimport)
#endif


SIMPLEMATH_API class Vector2
{
public:
	int x;
	int y;
	SIMPLEMATH_API void Print();
};

