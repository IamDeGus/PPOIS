#include "Height.h"

Height::Height(double m) : m_(m)
{
    if ( m > 2.3 || m < 0.7)
        throw HeightException("Create height failed: incorrect value");
}

bool Height::operator==(const Height other) const
{
    return abs(this->m_ - other.m_) < 0.001;
}

double Height::toMetric() const
{
    return m_;
}

double Height::toImperial() const
{
    return m_ * 3.2808;
}
