#include "Ages.h"

Ages::Ages(int ages) : ages_(ages)
{
    if (ages > 150 || ages < 14)
        throw AgesException("Age create failed: inccorect age");
}


int Ages::getAges() const
{
    return ages_;
}


void Ages::IncreaseAges()
{
    ages_++;
}
