/* Read SimpleMath.h if you haven't already.
* 
*  Here we have a separate file that contains a class.
*  In much the same way that we can export functions from
*  our DLL, we can also export entire classes and select
*  functionality from them. Below you see that we export
*  the Vector2 class, as well as it's Print method.
*/

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

