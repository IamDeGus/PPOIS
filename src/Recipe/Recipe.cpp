#include "Recipe.h"


Recipe::Recipe(std::vector<Step> steps, EdibleUnit dish, RecipeDescription note)
               : step_chain(std::move(steps)), dish(dish), note(note){}

bool Recipe::operator==(const Recipe other) const
{
    return this->step_chain == other.step_chain &&
           this->dish == other.dish &&
           this->note == other.note;
}

std::unique_ptr<EdibleUnit> Recipe::getDish() const
{
    auto newDish = std::make_unique<EdibleUnit>(dish);
    return newDish;
}

std::vector<Step>& Recipe::getSteps()
{
    return step_chain;
}

RecipeDescription Recipe::getNote() const
{
    return note;
}
