#include "CookChecker.h"

#include <iostream>

bool CookChecker::RecipeXP(int xp, Recipe recipe){
    return xp >= Calculate::getXP(recipe);
}

bool CookChecker::RecipeEnergy(int energy, Recipe recipe){
    return energy >= Calculate::getEnergy(recipe);
}

bool CookChecker::RecipeStep(const Kitchen& kitchen, Recipe recipe){
    std::vector<Ingredient*> intermediate;
    for (auto& s: recipe.getSteps()){
        if (!(StepChecker::CheckKitchenUnit(s.getKitchen_unit(), kitchen.getUnits())    &&
              StepChecker::CheckTool(s.getTool(), kitchen.getUnits())                   &&
              StepChecker::CheckUtensil(s.getUtensil(), kitchen.getUnits())            &&
              StepChecker::CheckPurityStatus(s.getUtensil(), s.getTool(), kitchen.getUnits())))
            return false;
        for (auto& i : s.getIngredients()){
            if (!StepChecker::CheckIngredient(i, kitchen.getUnits()) && !StepChecker::CheckIngredient(i, intermediate))
                return false;
        }
        Ingredient* temp = new Ingredient(s.Do());
        intermediate.push_back(temp);
    }
    return true;
}

bool CookChecker::TimeToSleep(Date date, Date process)
{
    Date result(2025, 1, 1, 0, 0, 0, true);
    result = date;
    result += process;

    Date sleepLine(2025, 1, 1, 0, 0, 0, true);
    sleepLine = Date(date.getYear(), date.getMonth(), date.getDay(), 22, 0, 0, true);

    return result < sleepLine;
}

bool CookChecker::CheckBestBeforeDate(Date now, Ingredient item)
{
    return IngredientChecker::CheckDate(now, item);
}

bool CookChecker::CheckSupplier(std::string name, Supplier supplier, Date today)
{
    return SupplierChecker::GetIngredients(name, supplier, today);
}
