#include "Player.h"

#include <iostream>

typedef unsigned short ushort;

Player::Player()
{
	std::cout << "Player constructor" << std::endl;
	name = "Binky";
	invSize = 4;
	inventory = new short[invSize];

	for (ushort i = 0; i < invSize; i++)
	{
		inventory[i] = rand() & 100;
	}
}

Player::~Player()
{
	delete[] inventory;
	inventory = nullptr; // not essential here
}

void Player::Print()
{
	std::cout << "\nPlayer: " << name << std::endl;

	for (ushort i = 0; i < invSize; i++)
	{
		std::cout << inventory[i] << ", ";
	}
	std::cout << std::endl << std::endl;
}
