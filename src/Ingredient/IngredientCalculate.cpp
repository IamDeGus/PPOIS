#include "IngredientCalculate.h"

float IngredientCalculate::getVolumeCapacity(Ingredient item)
{
    return item.getWeight().getVolume() * Weight::Coefficient(item.getWeight().getMeasur()) / 500;
}

int IngredientCalculate::getEnergy(EdibleUnit item)
{
    return int (item.getKcal() * item.getWeight().Coefficient(item.getWeight().getMeasur()) * item.getWeight().getVolume() / 5000);
}
