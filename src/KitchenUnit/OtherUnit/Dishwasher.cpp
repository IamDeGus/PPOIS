#include "Dishwasher.h"

Dishwasher::Dishwasher(std::string name, KitchenUnitDescription description, int toolCapacity, int utensilCapacity)
    : KitchenUnit(name, description), toolCapacity(toolCapacity), utensilCapacity(utensilCapacity) {}

int Dishwasher::getToolCapacity() const
{
    return toolCapacity;
}

int Dishwasher::getUtensilCapacity() const
{
    return utensilCapacity;
}

void Dishwasher::Wash(std::vector<std::unique_ptr<Utensil>>& utensils, std::vector<std::unique_ptr<Tool>>& tools)
{
    int maxCoeff{0};
    if (utensils.size() > utensilCapacity || tools.size() > toolCapacity)
        throw KitchenUnitException("Dishwasher failed: capacity exceeded");
    
    for (auto& u : utensils){
        u->Dish();
    }

    for (auto& t : tools){
        t->Dish();
    }
}
