#pragma once

#include "../KitchenUnit.h"

class CookUnit : public KitchenUnit
{
private:
    int power;
public:
    CookUnit(std::string name, KitchenUnitDescription description, int power);
    
    int getPower() const;
};
