#pragma once


#include "../../Interfaces/IWValidator.h"

class PortionWeightValidator : public IWValidator
{
public:
    bool Validate(double g) override;
    double getCoeff() override;
};
