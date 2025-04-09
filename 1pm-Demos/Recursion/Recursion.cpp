// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "functions.h"
#include <chrono>

using namespace std;

typedef unsigned int (*IntCalcFunc)(unsigned int);
void testFactorial(string label, IntCalcFunc fact);
void testFibonacci(string label, IntCalcFunc fib);

int main()
{
    /*
    testFactorial("Iterative factorial (for): ", factorial_for);
    testFactorial("Iterative factorial (better): ", factorial_better);
    testFactorial("Recursive factorial: ", factorial_recursive);
    testFibonacci("Iterative Fibonacci: ", fib_iterative);
    testFibonacci("Recursive Fibonacci: ", fib_recursive);
    */

    int num = 40;
    unsigned int count = 0;
    auto start = chrono::high_resolution_clock::now();
    cout << "Recursive Fib(" << num << ") = " << fib_recursive_count(num, count);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\tTime: " << duration.count() << " ms" << endl;
    cout << "\tCount: " << count << endl;

    count = 0;
    unsigned int cache[50] = {0};
    start = chrono::high_resolution_clock::now();
    cout << "Recursive cached Fib(" << num << ") = " << fib_recursive_cached(num, count, cache);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\tTime: " << duration.count() << " ms" << endl;
    cout << "\tCount: " << count << endl;

    /*
    start = chrono::high_resolution_clock::now();
    cout << "Iterative Fib(" << num << ") = " << fib_iterative(num);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "\tTime: " << duration.count() << " ms" << endl;
    */

}


void testFibonacci(string label, IntCalcFunc fib)
{
    cout << endl << label << endl;
    cout << "Fib(5) = " << fib(5) << endl;
    cout << "Fib(7) = " << fib(7) << endl;
    cout << "Fib(10) = " << fib(10) << endl;
}

void testFactorial(string label, IntCalcFunc fact)
{
    cout << endl << label << endl;
    cout << "5! = " << fact(5) << endl;
    cout << "7! = " << fact(7) << endl;
    cout << "10! = " << fact(10) << endl;
}
