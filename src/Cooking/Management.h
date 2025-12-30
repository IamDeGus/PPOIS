#pragma once

#include <memory>
#include "../Recipe/Recipe.h"
#include "../Kitchen/Kitchen.h" 

#include "../Common/Types/Date/DateCalculate.h"
#include "../Common/Exeptions/ManagementExeption.h"

class Cooking;

class Management{
private:
    Cooking& cooking;
public:
    explicit Management(Cooking& cookingRef) : cooking(cookingRef) {}
    Management() = default;

    void addTime(Date adddate);
    void untilTime(Date newdate);
    
    void addDish(std::unique_ptr<EdibleUnit> dish);

    void removeIngredients(Recipe& recipe);
    void removeIngredient(Ingredient& ingredient);
    void ChangeClearStatus(Recipe& recipe);

    void XPManage(int delta);
    void EnergyManage(int delta);

    void addRecipe(std::string& name, Recipe& recipe);

    

    void IncreaseCookedDishes();
    void IncreaseEatenFood();
    void IncreaseSleptNights();
    void IncreaseAddedRecipe();
    void IncreaseRemovedIngredient();
    void IncreaseWashedUtils();
    void IncreaseWashedTools();

    void setDateLastCooked();
    void setDateLastEaten();
    void setDateLastRemoving();
    void setDateLastWash();
    void setDateLastAddRecipe();

    void addEatenFoodByName(const std::string& foodName);
    void addCookedDishesByName(const std::string& dishesName);
};

