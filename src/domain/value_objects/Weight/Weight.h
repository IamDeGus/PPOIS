#pragma once

#include <memory>
#include "../../Interfaces/IUnitConverter.h"
#include "../../Interfaces/IWValidator.h"
#include "BodyWeightValidator.h"
#include "../../Exceptions/WeightException.h"

class Weight : public IUnitConverter
{
private:
    std::shared_ptr<IWValidator> validator_;
    double weight_;

public:
    Weight(double weight, std::shared_ptr<IWValidator> validator);
    Weight(double weight);

    bool operator==(const Weight other) const;
    bool operator<(const Weight other) const;
    bool operator>(const Weight other) const;
    
    double operator+(const Weight other) const;
    double operator-(const Weight other) const;
    double operator*(const Weight other) const;

    double toMetric() const override;
    double toImperial() const override;
};
