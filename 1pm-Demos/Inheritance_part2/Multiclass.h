#pragma once
#include "Cleric.h"
#include "Sorcerer.h"

class Multiclass :
    public Cleric, public Sorcerer
{
public:
    Multiclass();
    Multiclass(std::string _name, float _magicPower, std::string _deity);
    ~Multiclass();

    void PrintData() override;
    void PrintType() /*!*/override;
};

