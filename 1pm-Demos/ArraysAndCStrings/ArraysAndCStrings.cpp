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
	cout << "defaultNums[1]: " << defaultNums[1] << endl;

	int allZeroes[5] = {};
	cout << "allZeroes[1]: " << allZeroes[1] << endl;

	int nums[5] = { 1, 3, 5, 7, 9 };
	cout << "nums[1]: " << nums[1] << endl;

	int partialInit[5] = { 1, 1 };
	cout << "partialInit[4]: " << partialInit[4] << endl;

	const unsigned int MY_DATA_SIZE = 100;
	int myData[MY_DATA_SIZE] = { 123 };
	cout << "myData array size: " << sizeof(myData) << endl;
	cout << "myData array length: " << sizeof(myData) / sizeof(int) << endl;
	cout << "myData[0]: " << myData[0] << endl << endl;

	printSize(myData, MY_DATA_SIZE);

	// *** C STYLE STRINGS ***
	// char name[5] = "Shiro";
	//                  | <<- null term --- '\0'
	char firstName[6] = "Shiro";
	cout << firstName << endl;
	//firstName[5] = '!'; // BAD IDEA -- overwrites the null term.
	//cout << firstName << endl;

	char lastName[6] = " Mesh";

	// char fullName[50];
	// fullName = firstName;  // can't reassign cstrings
	char fullName[50] = "?";

	//fullName += lastName; // also can't auto append
	strcpy_s(fullName, firstName);
	strcat_s(fullName, lastName);
	// other cstring functions: strlen, strchr
	if (strchr(fullName, 'h'))
	{
		// found it and return WHERE it found it
		cout << strchr(fullName, 'h') << endl << endl;
	}

	// *** INPUT ***
	char username[100];
	cout << "Enter username: ";
	cin.getline(username, 100);
	cout << "Hello " << username << endl;

	char input;
	cout << "Enter a letter: ";
	cin >> input; // Removes a char from the cin buffer
	cout << "Your letter: " << input << endl;
}

void printSize(int data[], const unsigned size)
{
	cout << "data array size: " << sizeof(data) << endl;
	cout << "data array length: " << sizeof(data) / sizeof(int) << endl;
	cout << "size: " << size << endl;
	cout << "data[0]: " << data[0] << endl;
	cout << "data[size-1]: " << data[size-1] << endl << endl;
}