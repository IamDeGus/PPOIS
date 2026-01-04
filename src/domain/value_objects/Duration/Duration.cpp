#include "Duration.h"

Duration::Duration(double sec) : sec_(sec)
{
    if (sec < 0)
        throw DurationException("Create Duration failed: incorrect value");
}

Duration Duration::operator+(const Duration other)
{
    return Duration(this->sec_ + other.sec_);
}

Duration Duration::operator-(const Duration other)
{
    return Duration(this->sec_ - other.sec_);
}

Duration Duration::operator*(const int n)
{
    return Duration(this->sec_ * n);
}

double Duration::getDuration() const
{
    return sec_;
}
