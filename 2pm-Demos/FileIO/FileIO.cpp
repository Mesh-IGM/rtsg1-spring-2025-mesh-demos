// FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream outFile = ofstream("test.txt"/*, std::ios::app*/);
	if (outFile.is_open())
	{
		outFile << "Hello File IO!" << endl;
		outFile << "Next line";
		outFile << " - Same line";
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
	string fileAsString = string(
		istreambuf_iterator<char>(inFile),
		istreambuf_iterator<char>()
	);
	inFile.close();
	cout << fileAsString << endl << endl;

	// CSV - Name,1,2,3
	// JSON
	// custom
	string saveData = "Health: 50, Level: 10";

	const int OBFUSCATION_KEY = 612431563;

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
	string loadedSaveData = string(
		istreambuf_iterator<char>(inFile),
		istreambuf_iterator<char>()
	);
	inFile.close();
	for (int i = 0; i < loadedSaveData.length(); i++)
	{
		loadedSaveData[i] ^= OBFUSCATION_KEY;
	}

	cout << loadedSaveData << endl << endl;


	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	ifstream mapFileIn = ifstream("level1.map", ios::binary);

	string line;
	while (mapFileIn.good())
	{
		getline(mapFileIn, line);
		cout << line << endl;
	}
	mapFileIn.close();

}
