#pragma once


#include "Ingredient.h"
#include "../Common/Types/Grade/Grade.h"


class Spice : public Ingredient
{
private:
    Grade tasteIntensity;
    Grade aromaIntensity;
public:
    Spice(const std::string &name, const Date &date, const Weight &weight,
          Grade tasteIntensity, Grade aromaIntensity);
    
    Grade getTasteIntensity() const;
    Grade getAromaIntensity() const;
};
