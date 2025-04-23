// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include "FibCalc.h"
using namespace std;

void printHello()
{
	cout << "Hello" << endl;
}

void printGoodbye(string name)
{
	cout << "Goodbye " << name << endl;
	this_thread::sleep_for(3s);
}

int main()
{
	/*
	printHello();
	printGoodbye();
	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Before sleep" << endl;
	this_thread::sleep_for(3s);
	cout << "After sleep" << endl << endl;

	printHello();
	printGoodbye("Shiro");

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	thread helloThread(printHello);
	thread goodbyeThread(printGoodbye, "Lacy");

	helloThread.join(); // wait for it
	cout << "Hello thread done" << endl;

	goodbyeThread.join(); // wait for it
	cout << "Goodbye thread done" << endl;
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	*/
	// no threads
	FibCalc fib = FibCalc();
	fib.PrintFibNum(5);
	for (int i = 1; i < 45; i++)
	{
		fib.PrintFibNum(i);
	}

	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	vector<thread*> fibThreads;

	for (int i = 0; i < 45; i++)
	{
		fibThreads.push_back(new thread(&FibCalc::PrintFibNum, fib, i+1));
	}

	for (int i = 0; i < 45; i++)
	{
		fibThreads[i]->join();
		delete fibThreads[i];
	}
}

