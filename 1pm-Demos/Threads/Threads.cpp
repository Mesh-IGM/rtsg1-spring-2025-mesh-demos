// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>
#include <future>
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

void testFuture(promise<unsigned int>* promiseObj)
{
	FibCalc fib = FibCalc();
	cout << "Starting calc" << endl;
	unsigned int val = fib.CalcFibNum(10);
	promiseObj->set_value(val);
	cout << "Promise fufilled" << endl;
}

int main()
{
	
	//printHello();
	//printGoodbye();
	
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
	// no threads
	FibCalc fib = FibCalc();
	fib.PrintFibNum(5);
	for (int i = 1; i < 20; i++)
	{
		fib.PrintFibNum(i);
	}
	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	vector<thread*> fibThreads;

	for (int i = 0; i < 20; i++)
	{
		fibThreads.push_back(new thread(&FibCalc::PrintFibNum, fib, i+1));
	}

	for (int i = 0; i < 20; i++)
	{
		fibThreads[i]->join();
		delete fibThreads[i];
	}

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//vector<thread*> fibThreads;
	//FibCalc fib = FibCalc();
	mutex coutMutex;
	fibThreads.clear();
	for (int i = 0; i < 45; i++)
	{
		fibThreads.push_back(new thread(&FibCalc::PrintFibNumMtx, fib, i + 1, &coutMutex));
	}

	for (int i = 0; i < 45; i++)
	{
		fibThreads[i]->join();
		delete fibThreads[i];
	}
	
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	promise<unsigned int> promiseObject;
	future<unsigned int> futureInt = promiseObject.get_future();
	thread bgThread = thread(testFuture, &promiseObject);

	while (true)
	{
		cout << "game loop" << endl;
		if (futureInt._Is_ready())
		{
			cout << futureInt.get() << endl;
			break;
		}
	}
	bgThread.join();
	

	// auto -- figure out the type at compile time
	// = [capsture clause](params) -> returnType {function body};
	int y = 2;
	auto myLambda = [&y](float x)
		{
			cout << "x is equal to " << x << endl;
			cout << "y is equal to " << y << endl;
			y++;
		};

	myLambda(12);
	cout << "y after lambda " << y << endl;

	auto threadLambda = [](int num) { cout << "Thread run with num = " << num << endl; };
	thread t1 = thread(threadLambda, 1);
	thread t2 = thread(threadLambda, 2);
	t1.join();
	t2.join();

	thread lambdaThread(
		[](int num) { cout << "Lambda Thread run with num = " << num << endl; },
		10
	);
	lambdaThread.join();
}

