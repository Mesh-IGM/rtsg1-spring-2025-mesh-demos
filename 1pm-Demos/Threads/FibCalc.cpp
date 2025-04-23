#include "FibCalc.h"
#include <iostream>
using namespace std;

void FibCalc::PrintFibNum(int num)
{
	cout << num << " = " << CalcFibNum(num) << endl;
}

unsigned int FibCalc::CalcFibNum(int num)
{
	// intentionally inefficient recursion
	if (num <= 2)
	{
		return 1;
	}
	return CalcFibNum(num - 1) + CalcFibNum(num - 2);
}
