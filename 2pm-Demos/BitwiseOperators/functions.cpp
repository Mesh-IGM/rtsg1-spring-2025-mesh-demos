#include <iostream>
#include <bitset>
#include "functions.h"
using namespace std;

// "do I care?"
bool resolveCollision(short targetObjLayer, short objMask)
{
	// 0010 & 0011 --> 0010 
	// 0010 & 1100 --> 0000
	return (targetObjLayer & objMask); // != 0;
}

void printOneShort(const char label[], short num)
{
	cout << label << "\t\t\tDecimal: " << num;
	cout << "\t\tBinary: " << bitset<16>(num) << endl;
}


void printTwoShorts(short a, short b)
{
	printOneShort("A", a);
	printOneShort("B", b);
}

void doStuff(int numTimes)
{
	for (int i = 0; i < numTimes; i++)
	{
		cout << i << ", ";
		int j = i * i * 42;
	}
	cout << endl;
}