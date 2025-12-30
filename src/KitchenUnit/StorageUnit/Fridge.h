#pragma once

#include <vector>

#include "StorageUnit.h"
#include "../../Ingredient/EdibleUnit.h"
#include "../../Ingredient/Liquid.h"
#include "../../Common/Types/Weight/Weight.h"
#include "../../Common/Types/Temperature/Temperature.h"
#include "../../Ingredient/IngredientCalculate.h"

class Management;

class Fridge : public StorageUnit<EdibleUnit>
{
private:
    Temperature t;

public:
    Fridge(std::vector<std::unique_ptr<EdibleUnit>> units, KitchenUnitDescription description, int capacity, std::string name, Temperature t)
        : StorageUnit<EdibleUnit>(std::move(units), description, capacity, name), t(t) {};

    int getCapacityUsed() const override;

    Temperature getT() const;

protected:
    void addItem(std::unique_ptr<EdibleUnit> unit) override;
    void removeItem(EdibleUnit* unit) override;

    friend class Management;
};
