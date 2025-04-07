// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

typedef unsigned int (*FactorialFunc)(unsigned int);
void testFactorial(string label, FactorialFunc fact);

int main()
{
    testFactorial("Iterative factorial (for): ", factorial_for);
    testFactorial("Iterative factorial (better): ", factorial_better);
    testFactorial("Recursive factorial: ", factorial_recursive);
}

void testFactorial(string label, FactorialFunc fact)
{
    cout << endl << label << endl;
    cout << "5! = " << fact(5) << endl;
    cout << "7! = " << fact(7) << endl;
    cout << "10! = " << fact(10) << endl;
}
