#include "PersonMetaData.h"

PersonMetaData::PersonMetaData(int cooked, int eaten, int slept, int addedRec, 
                               int removedIng, int washedU, int washedT,
                               const Date& lastCooked, const Date& lastEaten,
                               const Date& lastRemoving, const Date& lastWash,
                               const Date& lastAddRecipe,
                               const std::map<std::string, int>& eatenByName,
                               const std::map<std::string, int>& cookedByName)
    : cookedDishes(cooked), eatenFood(eaten), sleptNights(slept),
      addedRecipe(addedRec), removedIngredient(removedIng),
      washedUtils(washedU), washedTools(washedT),
      DateLastCooked(lastCooked), DateLastEaten(lastEaten),
      DateLastRemoving(lastRemoving), DateLastWash(lastWash),
      DateLastAddRecipe(lastAddRecipe),
      eatenFoodbyName(eatenByName), cookedDishesbyName(cookedByName) {}

PersonMetaData::PersonMetaData()
    : cookedDishes(0), eatenFood(0), sleptNights(0),
      addedRecipe(0), removedIngredient(0),
      washedUtils(0), washedTools(0),
      DateLastCooked(), DateLastEaten(),
      DateLastRemoving(), DateLastWash(),
      eatenFoodbyName() {}

// Геттеры
int PersonMetaData::getCookedDishes() const
{
    return cookedDishes;
}

int PersonMetaData::getEatenFood() const
{
    return eatenFood;
}

int PersonMetaData::getSleptNights() const
{
    return sleptNights;
}

int PersonMetaData::getAddedRecipe() const
{
    return addedRecipe;
}

int PersonMetaData::getRemovedIngredient() const
{
    return removedIngredient;
}

int PersonMetaData::getWashedUtils() const
{
    return washedUtils;
}

int PersonMetaData::getWashedTools() const
{
    return washedTools;
}

Date PersonMetaData::getDateLastCooked() const
{
    return DateLastCooked;
}

Date PersonMetaData::getDateLastEaten() const
{
    return DateLastEaten;
}

Date PersonMetaData::getDateLastRemoving() const
{
    return DateLastRemoving;
}

Date PersonMetaData::getDateLastWash() const
{
    return DateLastWash;
}

Date PersonMetaData::getDateLastAddRecipe() const
{
    return DateLastAddRecipe;
}

std::map<std::string, int> PersonMetaData::getEatenFoodbyName() const
{
    return eatenFoodbyName;
}

std::map<std::string, int> PersonMetaData::getCookedDishesbyName() const
{
    return cookedDishesbyName;
}

bool PersonMetaData::operator==(const PersonMetaData other) const
{
    return this->cookedDishes == other.cookedDishes &&
           this->eatenFood == other.eatenFood &&
           this->sleptNights == other.sleptNights &&
           this->addedRecipe == other.addedRecipe &&
           this->removedIngredient == other.removedIngredient &&
           this->washedUtils == other.washedUtils &&
           this->washedTools == other.washedTools &&
           this->DateLastCooked == other.DateLastCooked &&
           this->DateLastEaten == other.DateLastEaten &&
           this->DateLastRemoving == other.DateLastRemoving &&
           this->DateLastWash == other.DateLastWash &&
           this->DateLastAddRecipe == other.DateLastAddRecipe &&
           this->cookedDishesbyName == other.cookedDishesbyName &&
           this->eatenFoodbyName == other.eatenFoodbyName;
}

void PersonMetaData::IncreaseCookedDishes()
{
    cookedDishes += 1;
}

void PersonMetaData::IncreaseEatenFood()
{
    eatenFood += 1;
}

void PersonMetaData::IncreaseSleptNights()
{
    sleptNights += 1;
}

void PersonMetaData::IncreaseAddedRecipe()
{
    addedRecipe += 1;
}

void PersonMetaData::IncreaseRemovedIngredient()
{
    removedIngredient += 1;
}

void PersonMetaData::IncreaseWashedUtils()
{
    washedUtils += 1;
}

void PersonMetaData::IncreaseWashedTools()
{
    washedTools += 1;
}

void PersonMetaData::setDateLastCooked(const Date& date)
{
    DateLastCooked = date;
}

void PersonMetaData::setDateLastEaten(const Date& date)
{
    DateLastEaten = date;
}

void PersonMetaData::setDateLastRemoving(const Date& date)
{
    DateLastRemoving = date;
}

void PersonMetaData::setDateLastWash(const Date& date)
{
    DateLastWash = date;
}

void PersonMetaData::setDateLastAddRecipe(const Date &date)
{
    DateLastAddRecipe = date;
}

void PersonMetaData::addEatenFoodByName(const std::string& foodName)
{
    if (eatenFoodbyName.find(foodName) != eatenFoodbyName.end()) {
        eatenFoodbyName[foodName]++;
    } else {
        eatenFoodbyName[foodName] = 1;
    }
}

void PersonMetaData::addCookedDishesByName(const std::string &dishesName)
{
    if (cookedDishesbyName.find(dishesName) != cookedDishesbyName.end()) {
        cookedDishesbyName[dishesName]++;
    } else {
        cookedDishesbyName[dishesName] = 1;
    }
}
