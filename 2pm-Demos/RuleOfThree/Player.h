#pragma once
class Player
{
private:
	unsigned int invSize;
	int* inventory; // managing data outside the allocated object

public:
	// Base setup for the demo
	Player(int _item1, int _item2, int _item3);
	void print();
	void swap(unsigned int _slot, int _newItem);

	// * 1 * -- custom destructor to cleanup external memory
	~Player();

	// * 2 *
	Player(const Player& _other);

	// * 3 *
	Player& operator=(const Player& _other);

};

