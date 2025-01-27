#include "functions.h"
#include <iostream>
#include <bitset>
using namespace std;


void printOneShort(short a)
{
	cout << "Short A\t\t\tDecimal: " << a;
	cout << "\t\tBinary: " << bitset<16>(a) << endl;
}

void printTwoShorts(short a, short b)
{
	cout << "Short A\t\t\tDecimal: " << a;
	cout << "\t\tBinary: " << bitset<16>(a) << endl;
	cout << "Short B\t\t\tDecimal: " << b;
	cout << "\t\tBinary: " << bitset<16>(b) << endl;
}

void loopAndDoStuff(short numTimes)
{
	for (int i = 0; i < numTimes; i++)
	{
		cout << i << ", ";
		int j = i * i * i;
	}
	cout << endl;
}