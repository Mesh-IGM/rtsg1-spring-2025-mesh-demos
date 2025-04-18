#pragma once

#ifdef SIMPLEMATH_EXPORTS
	#define SIMPLEMATH_API __declspec(dllexport)
#else
	#define SIMPLEMATH_API __declspec(dllimport)
#endif

extern "C" SIMPLEMATH_API int addition(int a, int b);
extern "C" SIMPLEMATH_API int subtraction(int a, int b);
extern "C" SIMPLEMATH_API int multiplication(int a, int b);
extern "C" SIMPLEMATH_API int division(int a, int b);


