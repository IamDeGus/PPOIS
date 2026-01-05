#pragma once

#include "../../Exceptions/BodyFatException.h"

class BodyFatPercentage
{
private:
    double percentage_;
public:
    BodyFatPercentage(double percentage);

    bool operator==(const BodyFatPercentage other) const;
    bool operator<(const BodyFatPercentage other) const;
    bool operator>(const BodyFatPercentage other) const;

    double getPercentage() const;
};
