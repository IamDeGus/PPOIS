#pragma once

#include <vector>
#include "StorageUnit.h"
#include "../../Ingredient/Ingredient.h"
#include "../../Ingredient/Liquid.h"
#include "../../Common/Types/Weight/Weight.h"
#include "../../Ingredient/IngredientCalculate.h"

class Management;

class Cupboard : public StorageUnit<Ingredient>
{
public:
    Cupboard(std::vector<std::unique_ptr<Ingredient>> units, KitchenUnitDescription description, int capacity, std::string name) 
        : StorageUnit<Ingredient>(std::move(units), description, capacity, name) {};

    int getCapacityUsed() const override;
protected:
    void addItem(std::unique_ptr<Ingredient> unit) override;
    void removeItem(Ingredient* unit) override;

    friend class Management;
};
