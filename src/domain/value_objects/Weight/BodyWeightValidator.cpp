#include "BodyWeightValidator.h"

bool BodyWeightValidator::Validate(double kg)
{
    return kg > 20 && kg < 300;
}

double BodyWeightValidator::getCoeff()
{
    return 2.2046;
}
