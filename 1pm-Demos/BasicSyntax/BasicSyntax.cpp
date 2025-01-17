// BasicSyntax.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


// line comment
/* blocks
*/

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main()
{
    /*std::*/cout << "Hello World!" << endl;
    // implicit
    // return 0;

    // Data types & Variables
    bool b1,b2,b3;
    int i1;
    bool myBool = true;
    char myChar = 'A';
    int myInt = 100;
    float myFloat = 100.01f;
    double myDouble = 100.01;

    // floats vs doubles
    if (myFloat == 100.01)
    {
        cout << "My float is equal to 100.01" << endl;
    }
    else
    {
        cout << "My float is NOT equal to 100.01" << endl;
    }

    if (myFloat == 100.01f)
    {
        cout << "My float is equal to 100.01f" << endl;
    }
    else
    {
        cout << "My float is NOT equal to 100.01f" << endl;
    }

    // Modifier keywords
    signed int mySignedInt = -100; // ~ -2 billion -> ~2 billion
    unsigned int myUnsignedInt = -100;  // 0 -> ~4.5 billion
    myInt = -100; // signed by default (in THIS version of C++)
    cout << "My unsigned int: " << myUnsignedInt << endl;
    cout << "My signed int: " << mySignedInt << endl;

    //------------------- Size modifiers -------------
    long int myLongInt = 1;
    short int myShortInt = 1;  // ~-32000 -> ~32000
    cout << sizeof(myInt) << endl;
    cout << sizeof(myLongInt) << endl;
    cout << sizeof(myShortInt) << endl;

    unsigned short myShort = 1; // can combine modifiers

    //------------------- Constants -------------
    const float PI = 3.14159f;
    //PI = 100;

    //------------------- Scope -------------
    int x = 10;

    if (x > 0)
    {
        int inside = 22;
    }

    //cout << inside << endl;

    double price = 12.99;
    int dollars = price; // implicit cast with data loss is allowed!
    cout << dollars << endl;

    float floatDollars = (int)price; // explicit cast
    cout << floatDollars << endl;

    float floatDollars2 = price;
    cout << floatDollars2 << endl;

    //------------------- Arithmetic Operators -------------
    int a = 2;
    int b = 3;

    int add = a + b;
    int sub = a - b;
    int mul = a * b;
    int div = a / b;
    int mod = b % a;

    double c = 2.5;
    double doublePlusInt = c + a;
    int intPlusDouble = c + a; // Loss of data
    //------------------- Assignment Operators -------------
    a = b;
    a += b;
    a -= b;
    a *= b;
    a /= b;
    a %= b;

    //------------------- Relational Operators -------------
    int large = 100;
    int small = 1;

    if (large > small) {}
    if (large >= small) {}
    if (large < small) {}
    if (large <= small) {}
    if (large == large) {}
    if (large != small) {}

    //------------------- Logical Operators -------------
    if (true && true) {}
    if (true && false) {}
    if (true || true) {}
    if (true || false) {}
    if (false || false) {}
    if (!true) {}
    if (!false) {}
}

