#pragma once

#include "../KitchenUnit.h"

#include <vector>
#include <memory>

#include "../../Utensil/Utensil.h"
#include "../../Tool/Tool.h"

#include "../../Common/Exeptions/KitchenUnitExeption.h"


class Dishwasher : public KitchenUnit
{
private:
    int toolCapacity;
    int utensilCapacity;
public:
    Dishwasher(std::string name, KitchenUnitDescription description, int toolCapacity, int utensilCapacity);
    
    int getToolCapacity() const;
    int getUtensilCapacity() const;

    void Wash(std::vector<std::unique_ptr<Utensil>>& utensils, std::vector<std::unique_ptr<Tool>>& tools);
};
