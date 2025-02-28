#pragma once

#include <vector>

// class name
class Pet
{
public:
	// const
	Pet();
	Pet(const char* name, unsigned short age);
	~Pet();
	void AddFriend(Pet* newFriend);
	char* GetName();

	// methods
	virtual void Print();

	int publicPetField;

// data - fields
private:
	char* name;
	unsigned short age;

protected:
	std::vector<Pet*> myFriends;
};