#pragma once

#include "../../Exceptions/DurationException.h"

class Duration
{
private:
    double sec_;

public:
    Duration(double sec);

    Duration operator+(const Duration other);
    Duration operator-(const Duration other);
    Duration operator*(const int n);

    double getDuration() const;
};

