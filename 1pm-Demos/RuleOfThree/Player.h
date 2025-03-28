#pragma once

class Player
{
private:
	int* inventory;
	unsigned int invSize;

public:
	// Base setup for demo
	Player(int _item1, int _item2, int _item3);
	void printInventory();
	void swapItem(unsigned int _slot, int _newItem);

	// #1 - destructor
	~Player();

	// #2 - deep copy constructor
	Player(const Player& _other);

	// #3 -- make assignment deep copy as well
	Player& operator=(const Player& _other);

};

