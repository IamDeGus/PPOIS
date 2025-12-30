#include "PurityHelper.h"

StateOfPurity PurityHelper::DecreasePurity(StateOfPurity nowPurity)
{
    switch (nowPurity)
    {
    case StateOfPurity::Clear:
        return StateOfPurity::NearlyClean;
    case StateOfPurity::NearlyClean:
        return StateOfPurity::SlightlySoiled;
    case StateOfPurity::SlightlySoiled:
        return StateOfPurity::QuiteDirty;
    case StateOfPurity::QuiteDirty:
        return StateOfPurity::Dirty;
    }
    return StateOfPurity::Dirty;
}

int PurityHelper::getTimeCoeff(StateOfPurity nowPurity)
{
    switch (nowPurity)
    {
    case StateOfPurity::Clear:
        return 1;
    case StateOfPurity::NearlyClean:
        return 2;
    case StateOfPurity::SlightlySoiled:
        return 3;
    case StateOfPurity::QuiteDirty:
        return 4;
    case StateOfPurity::Dirty:
        return 5;
    }
    return 5;
}
