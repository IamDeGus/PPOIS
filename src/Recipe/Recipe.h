#pragma once

#include <vector>
#include <memory>

#include "Step/Step.h"
#include "../Ingredient/EdibleUnit.h"
#include "../Common/Types/RecipeDescription/RecipeDescription.h"


class Recipe
{
private:
    std::vector<Step> step_chain;
    EdibleUnit dish;

    RecipeDescription note;

public:
    Recipe(std::vector<Step> steps, EdibleUnit dish, RecipeDescription note);


    bool operator== (const Recipe other) const;

    std::unique_ptr<EdibleUnit> getDish() const;
    std::vector<Step>& getSteps();
    RecipeDescription getNote() const;
};
