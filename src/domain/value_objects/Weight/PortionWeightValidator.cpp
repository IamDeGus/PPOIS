#include "PortionWeightValidator.h"

bool PortionWeightValidator::Validate(double g)
{
    return g > 0 && g < 1500;
}

double PortionWeightValidator::getCoeff()
{
    return 0.035274;
}
