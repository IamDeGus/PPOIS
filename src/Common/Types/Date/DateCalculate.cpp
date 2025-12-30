#include "DateCalculate.h"
#include <math.h>

Date DateCalculate::getDate(int xp, int neededXP, int energy)
{
    int sec{5000};
    sec = sec / (std::max((xp - neededXP + 1) / 100, 1)) / (energy / 20 + 1);
    Date result(0, 0, 0, 0, 0, sec, false);
    return result;
}
