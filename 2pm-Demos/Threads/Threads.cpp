// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
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

void testFuture(promise<unsigned int>* promiseObj)
{
	FibCalc fib = FibCalc();
	cout << "Starting calc" << endl;
	unsigned int val = fib.CalcFibNum(10);

	promiseObj->set_value(val);

	cout << "Finished calc" << endl;
}

int main()
{
	FibCalc fib = FibCalc();
	vector<thread*> threads;

	
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
	fib.PrintFibNum(6);
	for (int i = 0; i <= 45; i++)
	{
		fib.PrintFibNum(i);
	}
	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	for (int i = 0; i < 45; i++)
	{
		threads.push_back(new thread(&FibCalc::PrintFibNum, fib, i + 1));
	}


	for (int i = 0; i < 45; i++)
	{
		threads[i]->join();
		delete threads[i];
	}
	threads.clear();
	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	mutex coutMutex;
	for (int i = 0; i < 45; i++)
	{
		threads.push_back(new thread(&FibCalc::PrintFibNumMtx, fib, i + 1, &coutMutex));
	}


	for (int i = 0; i < 45; i++)
	{
		threads[i]->join();
		delete threads[i];
	}
	threads.clear();
		// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	promise<unsigned int> promiseObj;
	future<unsigned int> futureInt = promiseObj.get_future();
	thread bgThread = thread(testFuture, &promiseObj);
	cout << "Thread launched" << endl;
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

	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// auto -- figure out variable type at compile time
	// = [capture clause](parameters) -> returnType { body };
	int y = 1;
	auto myLambda = [&y](float x)
		{
			cout << "x is " << x << endl;
			cout << "y is " << y << endl;
			y++;
			this_thread::sleep_for(1s);
		};

	myLambda(2.3);
	myLambda(2.7);
	cout << "final y is " << y << endl;

	thread t1 = thread(myLambda, 4);
	thread t2 = thread(myLambda, 4);

	t1.join();
	t2.join();


	thread lambdaThread = thread(
		[](int num) {cout << "Thread lambda num is " << num << endl; },
		10
	);
	lambdaThread.join();
}
