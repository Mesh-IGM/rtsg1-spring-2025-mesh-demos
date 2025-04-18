/* Here we simply define the functions. Once we have defined
*  them, we can build the project. It can't be run because
*  it is a DLL and not an EXE, but it will build the DLL file
*  for us to use in the MathUser example (or any other project
*  that we want to link it to).
*/

#include "pch.h"
#include "SimpleMath.h"

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b + 1;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}
