#include "Kitchen.h"

Kitchen::Kitchen(std::vector<std::unique_ptr<KitchenUnit>> units, KitchenDescription description) 
    : units(std::move(units)), description(description) {}

const std::vector<std::unique_ptr<KitchenUnit>> &Kitchen::getUnits() const
{
    return units;
}

KitchenDescription Kitchen::getDescription() const
{
    return description;
}
