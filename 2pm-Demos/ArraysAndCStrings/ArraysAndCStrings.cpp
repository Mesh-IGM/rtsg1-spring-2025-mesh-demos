// ArraysAndCStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

void printSize(int data[], const unsigned int size);

int main()
{
	// *** ARRAYS ***
	int defaultNums[5];
	cout << "defaultNums[4]: " << defaultNums[4] << endl;

	int allZeroes[5] = {};
	cout << "allZeroes[4]: " << allZeroes[4] << endl;

	int nums[5] = { 1, 3, 5, 7, 9 };
	cout << "nums[4]: " << nums[4] << endl;

	int partialInit[5] = { 1, 2 };
	cout << "partialInit[4]: " << partialInit[4] << endl;
	cout << endl; // blank line

	const unsigned int MY_DATA_SIZE = 50;
	int myData[MY_DATA_SIZE] = {};
	myData[MY_DATA_SIZE-1] = 123;
	cout << "myData array size: " << sizeof(myData) << endl;
	cout << "myData array length: " << sizeof(myData) / sizeof(int) << endl;
	cout << "myData[MY_DATA_SIZE-1]: " << myData[MY_DATA_SIZE-1] << endl;
	printSize(myData, MY_DATA_SIZE);
	cout << endl; // blank line

	// *** C STYLE STRINGS ***
	// char name[5] = "Shiro"; - not big enough

	//                   | <-- null term. -- '\0'
	char name[6] = "Shiro";
	cout << name << endl;
	name[5] = '!'; // BAD IDEA
	cout << name << endl;

	char firstName[6] = "Shiro";
	char lastName[6] = " Mesh";
	char fullName[25] = "";

	strcpy_s(fullName, firstName);
	strcat_s(fullName, lastName);
	cout << fullName << endl;

	// other useful cstring functions: strlen, strchr

	if (strchr(fullName, ' '))
	{
		cout << strchr(fullName, ' ') << endl;
	}

	// *** INPUT ***
	char username[100];
	cout << "Enter your name: ";
	cin.getline(username, 100);
	cout << "hello " << username << endl;

	char input;
	cout << "Enter a letter: ";
	cin >> input;
	cout << "Your letter: " << input << endl;

	cin >> input;
	cout << "Your letter: " << input << endl;

	cin >> input;
	cout << "Your letter: " << input << endl;

	// See HW1 writeup for how to only get ONE char and ignore others until
	// the next newline
}


void printSize(int data[], const unsigned int size)
{
	cout << "data array size: " << sizeof(data) << endl;
	cout << "data array length: " << sizeof(data) / sizeof(int) << endl;
	cout << "data[size-1]: " << data[size-1] << endl;
	cout << endl; // blank line
}