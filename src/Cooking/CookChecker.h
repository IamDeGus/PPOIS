#pragma once

#include "../Kitchen/Kitchen.h"
#include "../Recipe/Recipe.h"
#include "../Recipe/Сalculate.h"
#include "../Recipe/Step/StepChecker.h"  
#include "../Ingredient/IngredientChecker.h"
#include "../Supplier/SupplierChecker.h"


class CookChecker
{
public:
    static bool RecipeXP(int xp, Recipe recipe);
    static bool RecipeEnergy(int energy, Recipe recipe);

    static bool RecipeStep(const Kitchen& kitchen, Recipe recipe);

    static bool TimeToSleep(Date date, Date process);

    static bool CheckBestBeforeDate(Date now, Ingredient item);
    static bool CheckSupplier(std::string name, Supplier supplier, Date today);
};
