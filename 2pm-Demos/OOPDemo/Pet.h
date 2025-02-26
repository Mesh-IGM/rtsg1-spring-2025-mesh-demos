#pragma once

// class name
class Pet
{
public:
	// const
	Pet();
	Pet(const char* name, unsigned short age, unsigned short numFriends);
	~Pet();

	// methods
	virtual void Print();

	int publicPetField;

// data - fields
private:
	char* name;
	unsigned short age;

protected:
	unsigned short numFriends;
	// vector of friends
};