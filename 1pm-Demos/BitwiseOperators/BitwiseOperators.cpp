// BitwiseOperators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	// *************************************************************************************
	// Binary Numbers
	// *************************************************************************************

	// run a loop to test cond breakpoints
	// doStuff(1200);

	// test helper methods - refactored to add some labeling and make main a little cleaner
	short test = 7890;
	printOneShort("Testing", test);
	cout << "\n\n\n";

	short test2 = 11110000; // bad -- overflow & interpreted as an int
	printOneShort("Bad init", test2);
	cout << "\n\n\n";

	short a = 0b11110000; // 0b --- interpret as binary
	short b = 0b10101010;
	printTwoShorts(a, b);
	cout << "\n\n\n";

	// *************************************************************************************
	// Bitwise AND, OR & XOR
	// comparisons
	// *************************************************************************************

	// Bitwise AND - &
	// If BOTH bits are 1, the resulting bit is 1. Otherwise 0.
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~
	// 1 0 1 0 0 0 0 0
	cout << "Bitwise AND - &" << endl;
	printTwoShorts(a, b);
	printOneShort("a & b", a & b);
	cout << "\n\n\n";

	// Bitwise OR - |
	// If EITHER bit is 1, resulting bit is 1. Otherwise 0.
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~
	// 1 1 1 1 1 0 1 0
	cout << "Bitwise OR - |" << endl;
	printTwoShorts(a, b);
	printOneShort("a | b", a | b);
	cout << "\n\n\n";

	// Bitwise XOR - ^
	// If ONE bit is 1, resulting bit is 1
	// Effectively -- are they different, bit by bit
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~
	// 0 1 0 1 1 0 1 0
	cout << "Bitwise XOR - ^" << endl;
	printTwoShorts(a, b);
	printOneShort("a ^ b", a ^ b);
	cout << "\n\n\n";

	// *************************************************************************************
	// Bitwise shifting & complement
	// *************************************************************************************

	// Shift left
	// - Move every bit left by #
	// Decimal shift: 20 <10< 1 ---> 200
	// Bit shift: 0000 0010 << 1 ---> 0000 0100 
	// Each shift effectively multiples by 2
	cout << "Shift left - << " << endl;
	//a = 256;
	printOneShort("a", a);
	printOneShort("a << 1", a << 1);
	printOneShort("a << 2", a << 2);
	cout << "\n\n\n";

	// Shift right
	// - Move every bit right by #
	cout << "Shift right - >> " << endl;
	printOneShort("a", a);
	printOneShort("a >> 1", a >> 1);
	printOneShort("a >> 2", a >> 2);
	cout << "\n\n\n";

	short c = 270;
	printOneShort("c", c);
	printOneShort("c >> 1", c >> 1);
	printOneShort("c >> 2", c >> 2);
	printOneShort("c >> 3", c >> 3);
	printOneShort("c >> 4", c >> 4);
	printOneShort("c >> 5", c >> 5);
	cout << "\n\n\n";

	// Complement
	// - Inverts each bit
	// 1 1 1 1 0 0 0 0
	// 0 0 0 0 1 1 1 1
	cout << "Complement - ~" << endl;
	printOneShort("a", a);
	printOneShort("~a", ~a);
	cout << "\n\n\n";
	cout << "\n\n\n";

	// *************************************************************************************
	// Usage example 1
	// *************************************************************************************

	short val1 = 0b1111000011110000;
	short val2 = 0b0000101000001010;

	// typically:
	/*
	short tmp = val1;
	val1 = val2;
	val2 = tmp;
	*/

	// NOT allowed to use a 3rd variable.

	// XOR Swap
	printOneShort("val1", val1);
	printOneShort("val2", val2);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	// Create a conversion mask
	val1 = val1 ^ val2; // tells us how to get from 1 value to the other
	printOneShort("val1 = val1 ^ val2", val1);

	// Convert val2 --> val1
	val2 = val2 ^ val1; // apply the mask to val2;
	printOneShort("val2 = val2 ^ val1", val2);

	// Convert *original* val1 (now in val2) --> val2
	val1 = val2 ^ val1; // apply the mask to val2 (orig val1);
	printOneShort("val1 = val2 ^ val1", val1);

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	printOneShort("val1", val1);
	printOneShort("val2", val2);

}
