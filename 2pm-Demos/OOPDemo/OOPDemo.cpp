// OOPDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Pet.h"
#include "Toy.h"
#include "Horse.h"

#include <vector>


void wrapper();

int main()
{
	wrapper();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS!" << endl;
	else
		cout << "\nNo memory leaks. :)" << endl;
}

void wrapper()
{
	//Pet* shiro = new Pet("Shiro", 7, 5);
	//cout << shiro->age << endl;
	//delete shiro;

	//Toy stick;
	//cout << stick.price << endl;

	Horse aiden;
	//cout << aiden.name << endl; // private in Pet
	//cout << aiden.numFriends << endl; // protected in Pet
	cout << aiden.publicPetField << endl; // public in Pet

	Horse* cosmo = new Horse("Cosmo", 5, 20);
	//cosmo->Print();

	vector<Horse*> herd = vector<Horse*>();
	herd.push_back(cosmo);
	herd.push_back(new Horse("Aiden", 24, 7));
	herd.push_back(new Horse("Moxie", 18, 7));
	herd.push_back(new Horse("Whiskey", 7, 7));

	cosmo->AddFriend(herd[1]);
	cosmo->AddFriend(herd[2]);

	cosmo->Print();

	for (int i = 0; i < herd.size(); i++)
	{
		delete herd[i];
	}
	herd.clear();


}