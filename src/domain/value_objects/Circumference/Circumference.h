#pragma once

#include "../../Interfaces/IUnitConverter.h"
#include "../../Exceptions/CircumferenceException.h"


class Circumference : public IUnitConverter
{
private:
    double cm_;
public:
    Circumference(double cm);

    bool operator==(const Circumference other) const;
    bool operator<(const Circumference other) const;
    bool operator>(const Circumference other) const;
    
    double operator+(const Circumference other) const;
    double operator-(const Circumference other) const;

    double toMetric() const override;
    double toImperial() const override;
};


