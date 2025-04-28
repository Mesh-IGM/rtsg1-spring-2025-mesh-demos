// STL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <map>

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
	nums[5] = 42;
	printArray("Starting array", nums, SIZE);

	std::sort(nums, nums + SIZE);
	printArray("Sorted array", nums, SIZE);

	std::sort(nums, nums + SIZE, [](int a, int b) {return a > b; });
	printArray("Sorted array (descending)", nums, SIZE);

	std::sort(nums, nums + SIZE);
	printArray("Before search", nums, SIZE);

	bool exists = std::binary_search(nums, nums + SIZE, 42);
	std::cout << "Exists? (0==false) " << exists << std::endl;

	bool allEven = std::all_of(nums, nums + SIZE, [](int n) {return n % 2 == 0; });
	std::cout << "All even? (0==false) " << allEven << std::endl;

	std::array<int, SIZE> arr;
	std::sort(arr.begin(), arr.end());
	printArray("Sorted STL array", &arr.front(), arr.size());

	std::map<std::string, int> empIDs;
	empIDs["Shiro"] = 1234;

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
