#pragma once

#include "../../Exceptions/HeartRateException.h"

class HeartRate
{
private:
    int bpm_;
public:
    HeartRate(int bpm);
    

    int getBPM() const;
};
