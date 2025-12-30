#pragma once

#include <typeinfo>

#include "Step.h"
#include "../../Ingredient/EdibleUnit.h"
#include "../../Ingredient/Liquid.h"
#include "../../Common/GetSomething/GetSomething.h"
#include "../../KitchenUnit/StorageUnit/StorageUnit.h"
#include "../../KitchenUnit/StorageUnit/Fridge.h"
#include "../../KitchenUnit/StorageUnit/Cupboard.h"
#include "../../KitchenUnit/StorageUnit/ToolStorage.h"
#include "../../KitchenUnit/StorageUnit/UtensilStorage.h"

#include "../../Common/VectorConverter/VectorConverter.h"
#include "../../Common/Types/StateOfPurity/StateOfPurity.h"

class StepChecker
{
public:
    static bool CheckKitchenUnit(std::string name, const std::vector<std::unique_ptr<KitchenUnit>>& units);
    static bool CheckTool(std::string name, const std::vector<std::unique_ptr<KitchenUnit>>& units);
    static bool CheckUtensil(std::string name, const std::vector<std::unique_ptr<KitchenUnit>>& units);

    static bool CheckIngredient(const Ingredient& ingredient, const std::vector<std::unique_ptr<KitchenUnit>>& units);
    static bool CheckIngredient(const Ingredient& ingredient, const std::vector<Ingredient*>& units);

    static bool CheckPurityStatus(std::string utensil, std::string tool, const std::vector<std::unique_ptr<KitchenUnit>>& units);
};

