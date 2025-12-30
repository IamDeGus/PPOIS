#include "IngredientChecker.h"


bool IngredientChecker::CheckDate(Date now, Ingredient item)
{
    return now < item.getDate();
}
