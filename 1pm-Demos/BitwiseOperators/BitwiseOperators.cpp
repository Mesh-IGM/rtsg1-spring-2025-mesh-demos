// BitwiseOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	loopAndDoStuff(1500);

	// test our helpers
	short test = 5678;
	printOneShort(test);
	printTwoShorts(test, test);
	cout << "\n\n\n";

	// setup data to test bitwise ops
	short test2 = 11110000; // this is an int
	printOneShort(test2);
	cout << "\n\n\n";

	short a = 0b11110000; // use the literal as binary -- 0b
	short b = 0b10101010; // use the literal as binary -- 0b
	printTwoShorts(a, b);
	cout << "\n\n\n";

	// Boolean AND -- &&
	// if (true && false) {}

	// Bitwise AND - &
	// If BOTH bits are 1, resulting bit is 1.
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~
	// 1 0 1 0 0 0 0 0
	cout << "*** Bitwise AND - & ***" << endl;
	printTwoShorts(a, b);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	printOneShort(a&b);
	cout << "\n\n\n";

	// Bitwise OR - |
	// If EITHER bit is 1, result bit is 1.
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~
	// 1 1 1 1 1 0 1 0
	cout << "*** Bitwise OR - | ***" << endl;
	printTwoShorts(a, b);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	printOneShort(a | b);
	cout << "\n\n\n";


}
