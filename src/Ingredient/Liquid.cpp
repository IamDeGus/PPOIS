#include "Liquid.h"


Liquid::Liquid(const std::string &name, const Date &date, 
               const Weight &weight, const float &kcal, 
               const Temperature &t, const float &density) 
               : EdibleUnit(name, date, weight, kcal, t), density(density) {}

bool Liquid::operator==(const Liquid other) const
{
    return this->getName() == other.getName() &&
           this->getWeight() == other.getWeight() &&
           this->getDate() == other.getDate() &&
           this->getT() == other.getT() &&
           this->getKcal() == other.getKcal() &&
           this->density == other.density;
}

float Liquid::getDensity() const{
    return density;
}
