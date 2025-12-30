#pragma once

#include "Ingredient.h"
#include "../Common/Types/Temperature/Temperature.h"

class EdibleUnit : public Ingredient
{
private:
    Temperature t;
    float kcal;

public:
    EdibleUnit(const std::string &name, const Date &date, 
               const Weight &weight, const float &kcal, const Temperature &t);

    bool operator==(const EdibleUnit other) const;

    Temperature getT() const;
    float getKcal() const;
};
