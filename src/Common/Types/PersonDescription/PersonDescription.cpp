#include "PersonDescription.h"
#include "../Date/DateCalculate.h"
#include <sstream>

// Конструктор с параметрами
PersonDescription::PersonDescription(int age, const Date& birthday, Gender gender, 
                                     Health health, const std::string& favoriteDish, 
                                     const Tool& favoriteTool, Temperature favoriteT, 
                                     const std::string& description)
    : age(age), birthday(birthday), gender(gender), health(health),
      favoriteDish(favoriteDish), favoriteTool(favoriteTool),
      favoriteT(favoriteT), IDescription(description) {}

bool PersonDescription::operator==(const PersonDescription other) const
{
    return this->age == other.age &&
           this->birthday == other.birthday &&
           this->gender == other.gender &&
           this->health == other.health &&
           this->favoriteDish == other.favoriteDish &&
           this->favoriteTool == other.favoriteTool &&
           this->favoriteT == other.favoriteT &&
           this->getDescription() == other.getDescription();
}

int PersonDescription::getAge() const
{
    return age;
}

Date PersonDescription::getBirthday() const
{
    return birthday;
}

Gender PersonDescription::getGender() const
{
    return gender;
}

Health PersonDescription::getHealth() const
{
    return health;
}

std::string PersonDescription::getFavoriteDish() const
{
    return favoriteDish;
}

Tool PersonDescription::getFavoriteTool() const
{
    return favoriteTool;
}

Temperature PersonDescription::getFavoriteTemperature() const
{
    return favoriteT;
}
