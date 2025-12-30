#pragma once

#include "EdibleUnit.h"
#include "../Common/Types/Weight/Weight.h"

class Liquid : public EdibleUnit
{
private:
    float density;
public:
    Liquid(const std::string &name, const Date &date, 
           const Weight &weight, const float &kcal, 
           const Temperature &t, const float &density);

    bool operator==(const Liquid other) const;


    float getDensity() const;
};
