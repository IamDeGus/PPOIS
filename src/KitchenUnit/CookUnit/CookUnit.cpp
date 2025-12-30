#include "CookUnit.h"

CookUnit::CookUnit(std::string name, KitchenUnitDescription description, int power) 
    : KitchenUnit(name, description), power(power) {}

int CookUnit::getPower() const
{
    return power;
}
