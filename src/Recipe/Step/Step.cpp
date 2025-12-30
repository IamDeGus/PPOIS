#include "Step.h"

Step::Step(std::vector<Ingredient> ingredients, std::string kitchen_unit,
         std::string tool, std::string utensil, int complexity, std::string name)
         : ingredients(ingredients), kitchen_unit(kitchen_unit),
           tool(tool), utensil(utensil), complexity(complexity),
           name(name) {}

bool Step::operator==(const Step other) const
{
    return this->ingredients == other.ingredients &&
           this->utensil == other.utensil &&
           this->tool == other.tool &&
           this->complexity == other.complexity &&
           this->name == other.name;
}

Ingredient Step::Do() const
{
    std::string resultSTR;
    resultSTR += "__" + name;
    for (auto &ingr : ingredients){
        resultSTR += "_" + ingr.getWeight().getStringWeight() + "_" + ingr.getName();
    }
    Weight resultW(1, Measur::Piece);

    Ingredient result(resultSTR, Date(), resultW);
    return result;
}

int Step::getComplexity() const{
    return complexity;
}

std::string Step::getName() const
{
    return name;
}

std::vector<Ingredient>& Step::getIngredients(){
    return ingredients;
}

std::string Step::getKitchen_unit() const
{
    return kitchen_unit;
}

std::string Step::getTool() const
{
    return tool;
}

std::string Step::getUtensil() const
{
    return utensil;
}
