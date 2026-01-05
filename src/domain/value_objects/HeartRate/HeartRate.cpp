#include "HeartRate.h"

HeartRate::HeartRate(int bpm) : bpm_(bpm)
{
    if (bpm < 30 || bpm > 220)
        throw HeartRateException("Create HeartRate failed: incorrect value");
}

int HeartRate::getBPM() const
{
    return bpm_;
}
