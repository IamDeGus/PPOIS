#include "Spice.h"


Spice::Spice(const std::string &name, const Date &date, const Weight &weight,
             Grade tasteIntensity, Grade aromaIntensity) 
            : Ingredient(name, date, weight), tasteIntensity(tasteIntensity),
              aromaIntensity(aromaIntensity) {}

Grade Spice::getTasteIntensity() const
{
    return tasteIntensity;
}

Grade Spice::getAromaIntensity() const
{
    return aromaIntensity;
}
