#pragma once


#include "../../Interfaces/IWValidator.h"


class BodyWeightValidator : public IWValidator
{
public:
    bool Validate(double kg) override;
    double getCoeff() override;
};
