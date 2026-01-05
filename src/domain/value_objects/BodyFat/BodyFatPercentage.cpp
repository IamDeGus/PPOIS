#include "BodyFatPercentage.h"

BodyFatPercentage::BodyFatPercentage(double percentage)
    : percentage_(percentage)
{
    if (percentage > 100 || percentage < 0)
        throw BodyFatException("Create BodyFatPercentage failed: incorrect value");
}


bool BodyFatPercentage::operator==(const BodyFatPercentage other) const
{
    return abs(this->percentage_ - other.percentage_) < 0.001;
}

bool BodyFatPercentage::operator<(const BodyFatPercentage other) const
{
    return this->percentage_ < other.percentage_;
}

bool BodyFatPercentage::operator>(const BodyFatPercentage other) const
{
    return this->percentage_ > other.percentage_;
}


double BodyFatPercentage::getPercentage() const
{
    return percentage_;
}
