#pragma once
#include "Pet.h"

#include <string>

class Pigeon :
    public Pet
{
public:
    Pigeon();
    Pigeon(std::string name, int age, std::string nickname);
    ~Pigeon();
    void Print() override;
    void Fly();

private:
    std::string nickname;
};

