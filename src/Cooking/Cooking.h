#pragma once

#include "../Person/Person.h"
#include "../Kitchen/Kitchen.h"
#include "../Recipe/CookingBook.h"
#include "../Ingredient/EdibleUnit.h"
#include "../Supplier/Supplier.h"

#include "../Common/Types/Date/Date.h"
#include "../Recipe/RecipeChecker.h"

#include "../Common/Exeptions/XpExeption.h"
#include "../Common/Exeptions/EnergyExeption.h"
#include "../Common/Exeptions/StepExeption.h"
#include "../Common/Exeptions/CookExeption.h"
#include "../Common/Exeptions/SupplierExeption.h"

#include "../Ingredient/IngredientCalculate.h"

#include "../KitchenUnit/OtherUnit/Dishwasher.h"
#include "../KitchenUnit/StorageUnit/StorageUnit.h"
#include "../Common/Types/StateOfPurity/PurityHelper.h"


#include "CookChecker.h"
#include "CookLimits.h"

class Management;

class Cooking
{
protected:
    Person cook;
    Kitchen kitchen;
    CookingBook recipes;

    Date date;

    friend class Management;

public:

    Cooking(Person cook, Kitchen&& kitchen, CookingBook recipes, Date date);
    
    void Cook(Recipe recipe);
    void Eat(EdibleUnit food);
    void RemoveSpoiledFood();

    void Sleep();
    void WashDish(std::vector<std::unique_ptr<Utensil>>&& utensils, std::vector<std::unique_ptr<Tool>>&& tools);

    void AddRecipe(std::string& name, Recipe& recipe);

    void PickUPSupplier(Supplier& supplier);

    Person& getCook();
    const Kitchen& getKitchen() const;
    const CookingBook& getRecipes() const;

    const Date& getDate() const;

    template<typename T>
    void RemoveSpoiledFood(StorageUnit<T>& unit);
};

