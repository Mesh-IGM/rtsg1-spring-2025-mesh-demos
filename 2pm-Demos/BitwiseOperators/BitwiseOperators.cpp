// BitwiseOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	doStuff(1200);

	// test helper methods
	short test = 7890;
	printOneShort(test);
	cout << "\n\n\n";

	short test2 = 11110000; // bad -- overflow & interpreted as an int
	printTwoShorts(test, test2);
	cout << "\n\n\n";

	short a = 0b11110000; // 0b --- interpret as binary
	short b = 0b10101010;
	printTwoShorts(a, b);
	cout << "\n\n\n";


	// Boolean AND - &&
	// if (true && false) {} 
	
	// Bitwise AND - &
	// If BOTH bits are 1, the resulting bit is 1. Otherwise 0.
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~
	// 1 0 1 0 0 0 0 0
	cout << "Bitwise AND - &" << endl;
	printTwoShorts(a, b);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	printOneShort(a & b);
	cout << "\n\n\n";

	// Bitwise OR - |
	// If EITHER bit is 1, resulting bit is 1. Otherwise 0.
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~
	// 1 1 1 1 1 0 1 0
	cout << "Bitwise OR - |" << endl;
	printTwoShorts(a, b);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	printOneShort(a | b);
	cout << "\n\n\n";

}
