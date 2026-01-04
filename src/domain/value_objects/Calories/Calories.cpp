#include "Calories.h"

Calories::Calories(double calories) : calories_(calories)
{
    if(calories_ < 0)
        throw CaloriesException("Create calories failed: incorrect value");
}

bool Calories::operator==(const Calories other) const
{
    return abs(this->calories_ - other.calories_) < 0.001;
}

bool Calories::operator<(const Calories other) const
{
    return this->calories_ < other.calories_;
}

bool Calories::operator>(const Calories other) const
{
    return this->calories_ > other.calories_;
}

Calories Calories::operator+(const Calories other) const
{
    return Calories(this->calories_ + other.calories_);
}

Calories Calories::operator-(const Calories other) const
{
    return Calories(this->calories_ - other.calories_);
}

Calories Calories::operator*(const int n) const
{
    return Calories(this->calories_ * n);
}

double Calories::getCalories() const
{
    return calories_;
}
