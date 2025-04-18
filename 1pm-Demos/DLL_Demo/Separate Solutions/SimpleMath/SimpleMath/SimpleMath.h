/* In this file, we are setting up the functions that our DLL will be
*  exporting. Think of these like "public" functions, that people can
*  see outside of the DLL. We can also have "private" things that are
*  not exported but are used internally.
*/
#pragma once

/* First we are using the preprocessor to dynamically setup some code
*  for us. Whenever you make a DLL project, Visual Studio will create
*  a preprocessor macro called PROJECTNAME_EXPORTS for you. That means
*  if we build this project, SIMPLEMATH_EXPORTS will exist in this file.
* 
*  By saying #ifdef SIMPLEMATH_EXPORTS, we are saying "if this exists".
*  If it does, we will define a macro called SIMPLEMATH_API, and it will
*  be equal to the block of code _declspec(dllexport). This code can be
*  used to flag a function for export from the DLL (making it "public").
* 
*  If it isn't defined, we will instead set SIMPLEMATH_API to equal
*  _declspec(dllimport). This is because this .h file will also be
*  in the MathUser project, where SIMPLEMATH_EXPORTS won't be defined and
*  so we will tell it to import these functions rather than export them.
*/
#ifdef SIMPLEMATH_EXPORTS
	#define SIMPLEMATH_API __declspec(dllexport)
#else
	#define SIMPLEMATH_API __declspec(dllimport)
#endif


/* Here we are creating four functions. If we look at the righthand side,
*  we see a lot of familiar code. For example "int addition(int a, int b)
*  is a very familiar function declaration with a return type, name, and
*  parameters.
* 
*  On the left, we have extern "C" SIMPLEMATH_API. extern "C" tells the
*  compiler to not change the function name at compile time. This is
*  necessary to allow us to use the DLL with other projects.
* 
*  The SIMPLEMATH_API is simply copying the code we setup using the
*  #ifdef statement above.
* 
*  These functions are defined in SimpleMath.cpp.
*/
extern "C" SIMPLEMATH_API int addition(int a, int b);

extern "C" SIMPLEMATH_API int subtraction(int a, int b);

extern "C" SIMPLEMATH_API int multiplication(int a, int b);

extern "C" SIMPLEMATH_API int division(int a, int b);