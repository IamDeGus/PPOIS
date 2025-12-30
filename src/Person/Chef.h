#pragma once


#include "Person.h"

class Management;

class Chef : public Person
{
public:
    Chef(int xp, std::string name, PersonMetaData metaData, PersonDescription description);

protected:
    void TakeXP(int xp) override;
    void TakeEnergy(int energy) override;

    friend class Management;
};

