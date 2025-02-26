#pragma once
struct Toy
{
public:
	Toy();
	Toy(const char* name, float price);
	~Toy();
	void Print();

private:
	char* name;
	float price;
};

