#pragma once

#include <map>
#include <string>
#include "../Date/Date.h"

class Management;

class PersonMetaData
{
private:
    int cookedDishes;
    int eatenFood;
    int sleptNights;

    int addedRecipe;
    int removedIngredient;

    int washedUtils;
    int washedTools;

    Date DateLastCooked;
    Date DateLastEaten;
    Date DateLastRemoving;
    Date DateLastWash;
    Date DateLastAddRecipe;

    std::map<std::string, int> cookedDishesbyName;
    std::map<std::string, int> eatenFoodbyName;

public:
    PersonMetaData(int cooked, int eaten, int slept, int addedRec, 
                   int removedIng, int washedU, int washedT,
                   const Date& lastCooked, const Date& lastEaten,
                   const Date& lastRemoving, const Date& lastWash,
                   const Date& lastAddRecipe,
                   const std::map<std::string, int>& eatenByName,
                   const std::map<std::string, int>& cookedByName);
    
    PersonMetaData();

    int getCookedDishes() const;
    int getEatenFood() const;
    int getSleptNights() const;
    int getAddedRecipe() const;
    int getRemovedIngredient() const;
    int getWashedUtils() const;
    int getWashedTools() const;
    
    Date getDateLastCooked() const;
    Date getDateLastEaten() const;
    Date getDateLastRemoving() const;
    Date getDateLastWash() const;
    Date getDateLastAddRecipe() const;
    
    std::map<std::string, int> getEatenFoodbyName() const;
    std::map<std::string, int> getCookedDishesbyName() const;

    bool operator== (const PersonMetaData other) const;

protected:
    void IncreaseCookedDishes();
    void IncreaseEatenFood();
    void IncreaseSleptNights();
    void IncreaseAddedRecipe();
    void IncreaseRemovedIngredient();
    void IncreaseWashedUtils();
    void IncreaseWashedTools();
    
    void setDateLastCooked(const Date& date);
    void setDateLastEaten(const Date& date);
    void setDateLastRemoving(const Date& date);
    void setDateLastWash(const Date& date);
    void setDateLastAddRecipe(const Date& date);
    
    void addEatenFoodByName(const std::string& foodName);
    void addCookedDishesByName(const std::string& dishesName);

    friend class Management;
};
