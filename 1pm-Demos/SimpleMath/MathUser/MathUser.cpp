// MathUser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SimpleMath.h"
#include "Vector2.h"

using namespace std;

int main()
{
	cout << addition(1, 2) << endl;
	cout << subtraction(1, 2) << endl;
	cout << multiplication(1, 2) << endl;
	cout << division(1, 2) << endl;

	Vector2 myVector = Vector2();
	myVector.x = 10;
	myVector.y = 20;
	myVector.Print();
}
