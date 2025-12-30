#pragma once

#include <vector>
#include <string>
#include <memory>

#include "../../Ingredient/Ingredient.h"
#include "../../KitchenUnit/KitchenUnit.h"
#include "../../Tool/Tool.h"
#include "../../Utensil/Utensil.h"


class Step
{
protected:
    std::vector<Ingredient> ingredients;

    std::string kitchen_unit;
    std::string tool;
    std::string utensil;


    int complexity;
    std::string name;

public:
    Step(std::vector<Ingredient> ingredients, std::string kitchen_unit,
         std::string tool, std::string utensil, int complexity, std::string name);
    ~Step() = default;

    bool operator== (const Step other) const;

    Ingredient Do() const;

    int         getComplexity() const;
    std::string getName()       const;

    std::vector<Ingredient>& getIngredients();
    std::string getKitchen_unit() const;
    std::string getTool() const;
    std::string getUtensil() const;
};
