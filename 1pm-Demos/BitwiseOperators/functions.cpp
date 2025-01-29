#include <iostream>
#include <bitset>
#include "functions.h"
using namespace std;

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