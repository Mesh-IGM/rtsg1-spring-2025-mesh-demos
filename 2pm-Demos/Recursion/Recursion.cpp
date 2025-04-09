// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include "functions.h"
using namespace std;

typedef unsigned int (*IntCalcFunc)(unsigned int);
void testFactorial(string label, IntCalcFunc fact);
void testFibonacci(string label, IntCalcFunc fib);

int main()
{
    /*
    testFactorial("Iterative factorial (for): ", factorial_for);
    testFactorial("Iterative factorial (while): ", factorial_better);
    testFactorial("Recursive factorial: ", factorial_recursive);
    */

    //testFibonacci("Iterative fibonacci:", fibonacci_iterative);
    //testFibonacci("Recursive fibonacci:", fibonacci_recursive);

    int num = 40;

    auto start = chrono::high_resolution_clock::now();
    cout << "Iterative fib(" << num << ") = " << fibonacci_iterative(num) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\tTime: " << duration.count() << " ms" << endl;

    unsigned int count = 0;
    start = chrono::high_resolution_clock::now();
    cout << "Recursive fib(" << num << ") = " << fibonacci_recursive_count(num, count) << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\tTime: " << duration.count() << " ms" << endl;
    cout << "\tCount: " << count << endl;


    count = 0;
    unsigned int cache[50] = { 0 };
    start = chrono::high_resolution_clock::now();
    cout << "Recursive fib(" << num << ") = " << fibonacci_recursive_cached(num, cache, count) << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\tTime: " << duration.count() << " ms" << endl;
    cout << "\tCount: " << count << endl;

    for (int i = 0; i < 40; i++)
    {
        cout << fibonacci_recursive_count(i, count) << " ";
    }
    cout << endl;
}


void testFibonacci(string label, IntCalcFunc fib)
{
    cout << endl << label << endl;
    cout << "Fib(3) = " << fib(3) << endl;
    cout << "Fib(5) = " << fib(5) << endl;
    cout << "Fib(7) = " << fib(7) << endl;
}

void testFactorial(string label, IntCalcFunc fact)
{
    cout << endl << label << endl;
    cout << "0! = " << fact(0) << endl;
    cout << "5! = " << fact(5) << endl;
    cout << "7! = " << fact(7) << endl;
    cout << "10! = " << fact(10) << endl;
}