#include "KitchenUnit.h"

KitchenUnit::KitchenUnit(std::string name, KitchenUnitDescription description)
     : INameable(name), description(description) {}

bool KitchenUnit::operator==(const KitchenUnit other) const
{
    return this->getName() == other.getName() &&
           this->getDescription() == other.getDescription();
}

KitchenUnitDescription KitchenUnit::getDescription() const
{
    return description;
}
