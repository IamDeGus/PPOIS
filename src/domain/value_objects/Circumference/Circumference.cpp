#include "Circumference.h"

Circumference::Circumference(double cm) : cm_(cm)
{
    if (cm < 13)
        throw CircumferenceException("Create failed: incorrect value");
}


bool Circumference::operator==(const Circumference other) const
{
    return abs(this->cm_ - other.cm_) < 0.001;
}

bool Circumference::operator<(const Circumference other) const
{
    return this->cm_ < other.cm_;
}

bool Circumference::operator>(const Circumference other) const
{
    return this->cm_ > other.cm_;
}


double Circumference::operator+(const Circumference other) const
{
    return this->cm_ + other.cm_;
}

double Circumference::operator-(const Circumference other) const
{
    return this->cm_ - other.cm_;
}


double Circumference::toMetric() const
{
    return cm_;
}

double Circumference::toImperial() const
{
    return cm_ * 0.3937;
}
