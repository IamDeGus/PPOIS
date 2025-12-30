#include "Chef.h"

Chef::Chef(int xp, std::string name, PersonMetaData metaData, PersonDescription description) 
    : Person(xp, name, metaData, description){
    this->energy = PersonLimits::MaxEnergyC();
}

void Chef::TakeXP(int xp)
{
    if (xp > 0)
        this->xp += PersonLimits::ChefCoeff() * xp;
    else
        this->xp += xp / PersonLimits::ChefCoeff();

    if (this->xp < 0)
        this->xp = 1;
}

void Chef::TakeEnergy(int energy)
{
    this->energy += energy;

    if (this->energy > PersonLimits::MaxEnergyC())
        this->energy = PersonLimits::MaxEnergyC();

    if (this->energy < 0)
        this->energy = 0;
}
