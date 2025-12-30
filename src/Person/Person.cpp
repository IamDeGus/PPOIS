#include "Person.h"

Person::Person(int xp, std::string name, PersonMetaData metaData, PersonDescription description) 
    : xp(xp), INameable(name), metaData(metaData), description(description) {}

bool Person::operator==(const Person other) const
{
    return this->description == other.description &&
           this->metaData == other.metaData &&
           this->getName() == other.getName() &&
           this->description == other.description;
}

int Person::getXP() const
{
    return xp;
}

int Person::getEnergy() const
{
    return energy;
}

PersonMetaData &Person::getMetaData()
{
    return metaData;
}

PersonDescription Person::getDescription() const
{
    return description;
}

void Person::TakeXP(int xp)
{
    this->xp += xp;
    if (this->xp < 0)
        this->xp = 1;
}

void Person::TakeEnergy(int energy)
{
    this->energy += energy;

    if (this->energy > PersonLimits::MaxEnergyP())
        this->energy = PersonLimits::MaxEnergyP();

    if (this->energy < 0)
        this->energy = 0;
}
