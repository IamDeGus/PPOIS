#pragma once


#include "Ingredient.h"
#include "EdibleUnit.h"


class IngredientCalculate
{
public:
    static float getVolumeCapacity(Ingredient item);
    static int getEnergy(EdibleUnit item);

};
