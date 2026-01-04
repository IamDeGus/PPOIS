#pragma once

#include "../../Exceptions/CaloriesException.h"

class Calories
{
private:
    double calories_;
public:
    Calories(double calories);

    bool operator==(const Calories other) const;
    bool operator<(const Calories other) const;
    bool operator>(const Calories other) const;
    
    Calories operator+(const Calories other) const;
    Calories operator-(const Calories other) const;
    Calories operator*(const int n) const;
    
    double getCalories() const;
};
