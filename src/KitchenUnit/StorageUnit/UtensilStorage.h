#pragma once

#include <vector>
#include "StorageUnit.h"
#include "../../Utensil/Utensil.h"


class UtensilStorage : public StorageUnit<Utensil>
{
public:
    UtensilStorage(std::vector<std::unique_ptr<Utensil>> units, KitchenUnitDescription description, int capacity, std::string name) 
        : StorageUnit<Utensil>(std::move(units), description, capacity, name) {};
};
