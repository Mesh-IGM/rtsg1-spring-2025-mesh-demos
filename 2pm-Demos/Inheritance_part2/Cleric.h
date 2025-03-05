#pragma once
#include "Character.h"
class Cleric :
    /*!*/ virtual public Character
{
public:
    Cleric();
    Cleric(std::string _name, std::string _deity);

    ~Cleric();

    void PrintData() override;
    void PrintType() /*!*/override;

    std::string deity;
};

