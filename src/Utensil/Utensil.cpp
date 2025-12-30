#include "Utensil.h"


Utensil::Utensil(std::string name, StateOfPurity clearStatus, bool isHeatResistant) 
    : INameable(name), clearStatus(clearStatus), isHeatResistant(isHeatResistant) {};

StateOfPurity Utensil::getClearStatus() const
{
    return clearStatus;
}
bool Utensil::getIsHeatResistant() const
{
    return isHeatResistant;
};

bool Utensil::operator== (const Utensil other) const{
    return this->getName() == other.getName();
}

void Utensil::Dish() {
    clearStatus = StateOfPurity::Clear;
};

void Utensil::GetDirty(StateOfPurity newStatus){
    clearStatus = newStatus;
};
