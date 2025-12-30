#pragma once


#include "StateOfPurity.h"


class PurityHelper
{
public:
    static StateOfPurity DecreasePurity(StateOfPurity nowPurity);
    static int getTimeCoeff(StateOfPurity nowPurity);
};
