#include "Macros.h"

Macros::Macros(double proteins, double fats, double carbohydrates)
    : proteins_(proteins), fats_(fats), carbohydrates_(carbohydrates)
{
    if (proteins_ < 0 || fats_ < 0 || carbohydrates_ < 0)
        throw MacrosException("Macros create failed: incorrect values");
}

Macros Macros::operator+(const Macros &other) const
{
    return Macros(
        this->proteins_ + other.proteins_,
        this->fats_ + other.fats_,
        this->carbohydrates_ + other.carbohydrates_
    );
}

double Macros::getProteins() const
{
    return proteins_;
}

double Macros::getFats() const
{
    return fats_;
}

double Macros::getCarbohydrates() const
{
    return carbohydrates_;
}
