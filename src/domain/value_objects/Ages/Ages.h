#pragma once

#include "../../Exceptions/AgesException.h"

class Ages
{
private:
    int ages_;

public:
    Ages(int ages);

    int getAges() const;

protected:
    friend class PersonalInfo;

    void IncreaseAges();
};
