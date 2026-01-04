#pragma once


class IWValidator
{
public:
    virtual bool Validate(double) const = 0;
    virtual double getCoeff() const = 0;
};
