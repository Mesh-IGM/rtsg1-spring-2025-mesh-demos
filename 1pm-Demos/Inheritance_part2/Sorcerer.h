#pragma once
#include "Character.h"

class Sorcerer :
    /*!*/ virtual public Character
{
public:
    Sorcerer();
    Sorcerer(std::string _name, float _magicPower);
    ~Sorcerer();

    void PrintData() override;
    void PrintType() /*!*/override;

    float magicPower;
};

