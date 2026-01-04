#pragma once

#include "../../Interfaces/IUnitConverter.h"
#include "../../Exceptions/HeightException.h"

class Height : public IUnitConverter
{
private:
    double m_;

public:
    Height(double m);
    
    bool operator==(const Height other) const;

    double toMetric() const override;
    double toImperial() const override;
};
