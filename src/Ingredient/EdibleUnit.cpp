#include "EdibleUnit.h"


EdibleUnit::EdibleUnit(const std::string &name, const Date &date, 
            const Weight &weight, const float &kcal, const Temperature &t)
            : Ingredient(name, date, weight), kcal(kcal), t(t) {}

bool EdibleUnit::operator==(const EdibleUnit other) const
{
    return this->getName() == other.getName() &&
           this->getWeight() == other.getWeight() &&
           this->getDate() == other.getDate() &&
           this->t == other.t &&
           this->kcal == other.kcal;
}

Temperature EdibleUnit::getT() const{
    return t;
}

float EdibleUnit::getKcal() const{
    return kcal;
}
