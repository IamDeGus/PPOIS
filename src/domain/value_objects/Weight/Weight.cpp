#include "Weight.h"

Weight::Weight(double weight, std::shared_ptr<IWValidator> validator)
    : weight_(weight), validator_(validator)
{
    if (!validator_)
        throw WeightException("Validator cannot be null");
    if (!validator_->Validate(weight))
        throw WeightException("Weight create failed: incorrect value");
}

Weight::Weight(double weight)
    : Weight(weight, std::make_shared<BodyWeightValidator>()) {}

bool Weight::operator==(Weight other) const
{
    return abs(this->weight_ - other.weight_) < 0.001;
}

bool Weight::operator<(Weight other) const
{
    return this->weight_ < other.weight_;
}

bool Weight::operator>(Weight other) const
{
    return this->weight_ > other.weight_;
}


double Weight::operator+(Weight other) const
{
    return this->weight_ + other.weight_;
}

double Weight::operator-(Weight other) const
{
    return this->weight_ - other.weight_;
}

double Weight::operator*(Weight other) const
{
    return this->weight_ * other.weight_;
}

double Weight::toMetric() const
{
    return weight_;
}

double Weight::toImperial() const
{
    return weight_ * validator_->getCoeff();
}
