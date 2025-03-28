#include "Player.h"

#include <iostream>
using namespace std;

Player::Player(int _item1, int _item2, int _item3)
{
	cout << "Player(" << _item1 << ", " << _item2 << ", " << _item3 << ")" << endl;
	invSize = 3;
	inventory = new int[invSize] {_item1, _item2, _item3 };
}

void Player::printInventory()
{
	cout << "Inventory: ";
	for (unsigned int i = 0; i < invSize; i++)
	{
		cout << inventory[i] << " ";
	}
	cout << "which is at " << inventory << endl;
}

void Player::swapItem(unsigned int _slot, int _newItem)
{
	if (_slot < 0 || _slot >= invSize)
	{
		cout << "Invalid slot." << endl;
		return;
	}
	inventory[_slot] = _newItem;
}

Player::~Player()
{
	cout << "~Player()" << endl;
	delete[] inventory;
}

Player::Player(const Player& _other)
{
	cout << "Player(other)" << endl;

	// implicit shallow copy
	//invSize = _other.invSize;
	//inventory = _other.inventory;

	// we want a deep copy
	invSize = _other.invSize;
	inventory = new int[invSize];

	for (unsigned int i = 0; i < invSize; i++)
	{
		inventory[i] = _other.inventory[i];
	}
}

Player& Player::operator=(const Player& _other)
{
	cout << "Player =(other)" << endl;

	// check for self assignment
	if (this == &_other)
	{
		cout << "self assignment" << endl;
		return *this;
	}

	// clean up old memory!
	if (inventory != nullptr)
	{
		delete[] inventory;
	}

	// we want a deep copy
	invSize = _other.invSize;
	inventory = new int[invSize];

	std::copy(
		_other.inventory, // source start addr
		_other.inventory + _other.invSize, // source end addr
		inventory // dest start addr
	);
	return *this;
}
