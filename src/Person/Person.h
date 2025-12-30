#pragma once

#include "PersonLimits.h"
#include "../Common/Types/PersonMetaData/PersonMetaData.h"
#include "../Common/Types/PersonDescription/PersonDescription.h"

#include "../Kitchen/Kitchen.h"
#include "../Recipe/Recipe.h"

#include "../Common/I/INameable.h"

class Management;

class Person : public INameable
{
protected:
    int xp;
    int energy{PersonLimits::MaxEnergyP()};

    PersonMetaData metaData;
    PersonDescription description;

    int age;

public:
    Person(int xp, std::string name, PersonMetaData metaData, PersonDescription description);
    virtual ~Person() = default;

    bool operator== (const Person other) const;

    int getXP() const;
    int getEnergy() const;

    PersonMetaData &getMetaData();
    PersonDescription getDescription() const;
protected:
    virtual void TakeXP(int xp);
    virtual void TakeEnergy(int energy);

    friend class Management;
};
