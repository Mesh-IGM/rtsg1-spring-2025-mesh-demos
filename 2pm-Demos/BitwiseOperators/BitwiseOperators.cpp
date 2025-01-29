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
	// Bitwise AND, OR, XOR
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
	// If ONE bit is 1, resulting bit is 1.
	// Effectively, 1 if the bits are DIFFERENT
	// 1 1 1 1 0 0 0 0
	// 1 0 1 0 1 0 1 0
	// ~~~~~~~~~~~~~~~~
	// 0 1 0 1 1 0 1 0  
	cout << "Bitwise XOR - ^" << endl;
	printTwoShorts(a, b);
	printOneShort("a ^ b", a ^ b);
	cout << "\n\n\n";

	// *************************************************************************************

	// Shift Left - <<
	// base 10: 0023 <10< 1 ---> 230 // shift left, 1 place -- "place"
	// shift by 1 place effectively x10
	// base 2: 0b0100 << 1 ---> 1000 // shift left, 1 place
	// x2 per place
	cout << "Shift left - <<" << endl;
	printOneShort("a", a);
	printOneShort("a << 1", a << 1);
	printOneShort("a << 2", a << 2);
	cout << "\n\n\n";

	// Shift right - >>
	// effectively divides by 2
	cout << "Shift right - >>" << endl;
	a = 140;
	printOneShort("a", a);
	printOneShort("a >> 1", a>>1);
	printOneShort("a >> 2", a >> 2);
	printOneShort("a >> 3", a >> 3);
	cout << "\n\n\n";


	// Complement
	printOneShort("a", a);
	printOneShort("~a", ~a);
	cout << "\n\n\n";

	// *************************************************************************************
	// Example 1

	short val1 = 0b11110000; // 240
	short val2 = 0b10101010; // 170

	// TODO: Swap the values between variables.
	printOneShort("val1", val1);
	printOneShort("val2", val2);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	// typically
	/*
	short tmp = val1;
	val1 = val2;
	val2 = tmp;
	*/

	// NOT allowed to use a 3rd variable.

	// XOR Swap
	// xor them together and save it
	val1 = val1 ^ val2; // results in our conversion mask
	printOneShort("val1 = val1 ^ val2", val1);

	// use that to derive 1 value
	val2 = val2 ^ val1; // apply mask to orig val 2 --> orig val1
	printOneShort("val2 = val2 ^ val1", val2);

	// use it again to derive the other
	val1 = val2 ^ val1; // apply the mask to new val2 (orig val1) --> orig val2
	printOneShort("val1 = val2 ^ val1", val1);


	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	printOneShort("val1", val1);
	printOneShort("val2", val2);





}
