#pragma once
#include "Character.h"

#include <string>

class Sorcerer :
    public Character
{
public:
    Sorcerer();
    Sorcerer(std::string _name, int _numSpells);

    ~Sorcerer();

    void PrintData() override;
    void PrintType() /*override*/;

    int numSpells;

};

