// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "FibCalc.h"

using namespace std;

void printHello()
{
	cout << "Hello" << endl;
	//this_thread::sleep_for(3s);
}

void printGoodbye(string name)
{
	cout << "Goodbye " << name << "!" << endl;
}

int main()
{
	/*
	printHello();
	printGoodbye("Shiro");

	cout << "Before sleep" << endl;
	this_thread::sleep_for(3s);
	cout << "After sleep" << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	thread helloThread(printHello);
	thread goodbyeThread(printGoodbye, "Lacy");

	helloThread.join();
	cout << "Hello done" << endl;

	goodbyeThread.join();
	cout << "Goodbye done" << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// slow way
	FibCalc fib = FibCalc();
	fib.PrintFibNum(6);
	for (int i = 0; i <= 45; i++)
	{
		fib.PrintFibNum(i);
	}
	*/
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	FibCalc fib = FibCalc();
	vector<thread*> threads;

	for (int i = 0; i < 45; i++)
	{
		threads.push_back(new thread(&FibCalc::PrintFibNum, fib, i + 1));
	}


	for (int i = 0; i < 45; i++)
	{
		threads[i]->join();
		delete threads[i];
	}


}
