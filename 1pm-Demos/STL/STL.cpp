// STL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <algorithm> // STL algs
#include <array>
#include <map>
#include <string>

void printArray(const char* label, int* arr, const unsigned int SIZE);

int main()
{
	srand(time(NULL));
	const unsigned int SIZE = 10;
	int nums[SIZE];
	for (unsigned int i = 0; i < SIZE; i++)
	{
		nums[i] = (rand() % 100)*2;
	}
	printArray("Starting array", nums, SIZE);
	std::sort(nums, nums + SIZE);
	printArray("Sorted array", nums, SIZE);

	std::sort(nums, nums + SIZE, [](int a, int b) {return a > b;});
	printArray("Descending sorted array", nums, SIZE);

	nums[5] = 42;
	std::sort(nums, nums + SIZE);
	printArray("Before search", nums, SIZE);
	bool exists = std::binary_search(nums, nums + SIZE, 42);
	if (exists)
	{
		std::cout << "YAY!" << std::endl;
	}
	else
	{
		std::cout << ":(" << std::endl;
	}

	bool all = std::all_of(nums, nums + SIZE, [](int n) {return n % 2 == 0; });
	std::cout << "All even? " << all << std::endl;

	std::array<int, SIZE> stlArray;
	std::sort(stlArray.begin(), stlArray.end());
	printArray("Sorted STL array", &stlArray.front(), stlArray.size());

	std::map<std::string, int> empIDs;


}

void printArray(const char* label, int* arr, const unsigned int SIZE)
{
	std::cout << label << ":";
	/*
	for (unsigned int i = 0; i < SIZE; i++)
	{
		std::cout << " " << arr[i];
	}
	std::cout << std::endl;
	*/
	int* current = arr;
	while (current < arr + SIZE)
	{
		std::cout << " " << *current++;
	}
	std::cout << std::endl;
}

