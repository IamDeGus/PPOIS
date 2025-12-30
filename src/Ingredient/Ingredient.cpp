#include "Ingredient.h"


Ingredient::Ingredient(const std::string &name, const Date &date, const Weight &weight)
    : INameable(name), best_before_date(date), weight(weight) {}

const Date& Ingredient::getDate() const{
    return best_before_date;
}

const Weight& Ingredient::getWeight() const{
    return weight;
}

bool Ingredient::operator==(const Ingredient other) const
{
    return this->getName() == other.getName() &&
           this->weight == other.weight &&
           this->best_before_date == other.best_before_date;
}

Weight &Ingredient::getWeightt()
{
    return weight;
}
