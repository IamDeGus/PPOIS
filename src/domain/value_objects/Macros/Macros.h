#pragma once

#include "../../Exceptions/MacrosException.h"

class Macros
{
private:
    double proteins_;
    double fats_;
    double carbohydrates_;

public:
    Macros(double proteins, double fats, double carbohydrates);

    Macros operator+(const Macros& other) const;

    double getProteins() const;
    double getFats() const;
    double getCarbohydrates() const;
};


