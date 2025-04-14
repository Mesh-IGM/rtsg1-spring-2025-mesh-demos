// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	std::cout;
	std::cin;

	ofstream outFile = ofstream("test.txt"/*, std::ios::app*/);

	if (outFile.is_open())
	{
		outFile << "Hello File IO World" << endl;
		outFile << "Next Line";
		outFile << " - Same Line";
	}
	outFile.close();

	ifstream inFile("test.txt");

	char fileContent[200] = "";
	inFile.read(fileContent, 200);
	cout << fileContent << endl << endl;

	inFile.clear();
	inFile.seekg(5);
	char fileContent2[200] = "";
	inFile.read(fileContent2, 200);
	cout << fileContent2 << endl << endl;

	inFile.clear();
	inFile.seekg(0);
	string fileAsString = 
		string(
			istreambuf_iterator<char>(inFile),
			istreambuf_iterator<char>()
		);
	inFile.close();
	cout << fileAsString << endl << endl;

	// Name,1,2 -- CSV
	// JSON
	// Custom
	string saveData = "Lives: 5, Position: (5,10), Level: 3";
	const int OBFUSCATION_KEY = 31459487;

	for (int i = 0; i < saveData.length(); i++)
	{
		saveData[i] ^= OBFUSCATION_KEY;
	}

	outFile.open("saveData.txt");
	if (outFile.is_open())
	{
		outFile << saveData;
	}
	outFile.close();

	inFile.open("saveData.txt");
	string loadedSaveData =
		string(
			istreambuf_iterator<char>(inFile),
			istreambuf_iterator<char>()
		);
	inFile.close();

	for (int i = 0; i < loadedSaveData.length(); i++)
	{
		loadedSaveData[i] ^= OBFUSCATION_KEY;
	}
	cout << loadedSaveData << endl << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	string line;
	ifstream mapFileIn = ifstream("level1.map", ios::binary);

	while (mapFileIn.good())
	{
		getline(mapFileIn, line);
		cout << line << endl;
	}

	mapFileIn.close();
}