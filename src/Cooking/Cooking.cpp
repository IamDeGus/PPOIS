#include "Cooking.h"
#include "Management.h"

#include <iostream>


void Management::addTime(Date adddate){
    cooking.date += adddate;
}

void Management::untilTime(Date newdate){
    cooking.date = newdate;
}

void Management::addDish(std::unique_ptr<EdibleUnit> dish){
    if (dish->getT() == Temperature::Cool){
        Cupboard *cupboard = GetSomething::TakeThis<Cupboard, KitchenUnit>(cooking.kitchen.getUnits());
        cupboard->addItem(std::move(dish));
        return;
    } else{
        std::vector<Fridge*> fridge = GetSomething::TakeAllThis<Fridge, KitchenUnit>(cooking.kitchen.getUnits());
        for (auto& f : fridge){
            if (f->getT() == dish->getT()){
                f->addItem(std::move(dish));
                return;
            }
        }
    }
    throw ManagementException("Adding dish failed: no storage");
}

void Management::removeIngredients(Recipe& recipe)
{
    std::vector<const Ingredient*> intermediate;
    for (auto& s : recipe.getSteps()){
        for (auto& i : s.getIngredients()){
            bool skip{false};
            for (auto& before :intermediate){
                if (i == *before){
                    skip = true;
                    break;
                }
            }
            if (skip) continue;
            removeIngredient(i);
        }
        Ingredient* temp = new Ingredient(s.Do());
        intermediate.push_back(temp);
    }

}

void Management::removeIngredient(Ingredient& ingredient)
{
    EdibleUnit* ediblePtr = dynamic_cast<EdibleUnit*>(&ingredient);
    if (ediblePtr == nullptr || ediblePtr->getT() == Temperature::Cool){
        Cupboard *cupboard = GetSomething::TakeThis<Cupboard, KitchenUnit>(cooking.kitchen.getUnits());
        cupboard->removeItem(&ingredient);
        return;
    } else{
        std::vector<Fridge*> fridge = GetSomething::TakeAllThis<Fridge, KitchenUnit>(cooking.kitchen.getUnits());
        for (auto& f : fridge){
            if (f->getT() == ediblePtr->getT()){
                f->removeItem(ediblePtr);
                return;
            }
        }
    }
    throw ManagementException("Removing ingredient failed: no storage");
}

void Management::XPManage(int delta)
{
    cooking.cook.TakeXP(delta);
}

void Management::EnergyManage(int delta)
{
    cooking.cook.TakeEnergy(delta);
}

void Management::ChangeClearStatus(Recipe& recipe)
{
    std::vector<UtensilStorage*> utensilStorages = GetSomething::TakeAllThis<UtensilStorage, KitchenUnit>(cooking.kitchen.getUnits());
    std::vector<ToolStorage*> toolStorages = GetSomething::TakeAllThis<ToolStorage, KitchenUnit>(cooking.kitchen.getUnits());
    for (auto& s : recipe.getSteps()){

        for (auto& uunit : utensilStorages){
            for (auto& unit : uunit->getUnits()){
                if (s.getTool() == unit->getName())
                    unit->GetDirty(PurityHelper::DecreasePurity(unit->getClearStatus()));
            }
        }
        for (auto& tunit : toolStorages){
            for (auto& unit : tunit->getUnits()){
                if (s.getTool() == unit->getName())
                    unit->GetDirty(PurityHelper::DecreasePurity(unit->getClearStatus()));
            }
        }
    }
}

void Management::addRecipe(std::string& name, Recipe& recipe)
{
    cooking.recipes.AddRecipe(name, recipe);
}

void Management::IncreaseCookedDishes()
{
    cooking.cook.getMetaData().IncreaseCookedDishes();
}

void Management::IncreaseEatenFood()
{
    cooking.cook.getMetaData().IncreaseEatenFood();
}

void Management::IncreaseSleptNights()
{
    cooking.cook.getMetaData().IncreaseSleptNights();
}

void Management::IncreaseAddedRecipe()
{
    cooking.cook.getMetaData().IncreaseAddedRecipe();
}

void Management::IncreaseRemovedIngredient()
{
    cooking.cook.getMetaData().IncreaseRemovedIngredient();
}

void Management::IncreaseWashedUtils()
{
    cooking.cook.getMetaData().IncreaseWashedUtils();
}

void Management::IncreaseWashedTools()
{
    cooking.cook.getMetaData().IncreaseWashedTools();
}

void Management::setDateLastCooked()
{
    cooking.cook.getMetaData().setDateLastCooked(cooking.date);
}

void Management::setDateLastEaten()
{
    cooking.cook.getMetaData().setDateLastEaten(cooking.date);
}

void Management::setDateLastRemoving()
{
    cooking.cook.getMetaData().setDateLastRemoving(cooking.date);
}

void Management::setDateLastWash()
{
    cooking.cook.getMetaData().setDateLastWash(cooking.date);
}

void Management::setDateLastAddRecipe()
{
    cooking.cook.getMetaData().setDateLastAddRecipe(cooking.date);
}

void Management::addEatenFoodByName(const std::string &foodName)
{
    cooking.cook.getMetaData().addEatenFoodByName(foodName);
}

void Management::addCookedDishesByName(const std::string &dishesName)
{
    cooking.cook.getMetaData().addCookedDishesByName(dishesName);
}

// 
// =========================================================
// 



Cooking::Cooking(Person cook, Kitchen&& kitchen, CookingBook recipes, Date date) 
                 : cook(cook), kitchen(std::move(kitchen)), recipes(recipes), date(date){}


void Cooking::Cook(Recipe recipe){

    if (!CookChecker::RecipeXP(cook.getXP(), recipe))
        throw XpException("Cooking failed: lack of experience");
    if (!CookChecker::RecipeEnergy(cook.getEnergy(), recipe))
        throw EnergyException("Cooking failed: lack of energy");
    if (!CookChecker::RecipeStep(kitchen, recipe))
        throw StepException("Cooking failed: there is a lack of equipment or ingredients");

    Date process(0, 0, 0, 0, 0, 0, false);
    process = DateCalculate::getDate(cook.getXP(), Calculate::getXP(recipe), cook.getEnergy());
    if (!CookChecker::TimeToSleep(date, process))
        throw CookException("Cooking failed: it's too late to cook for so long");
    
    Management manager(*this);

    manager.ChangeClearStatus(recipe);
    manager.removeIngredients(recipe);
    manager.addDish(std::move(recipe.getDish()));
    manager.addTime(process);

    manager.IncreaseCookedDishes();
    manager.addCookedDishesByName(recipe.getDish()->getName());

    manager.setDateLastCooked();

    manager.XPManage(Calculate::getEnergy(recipe) / 2 + 1);
    manager.EnergyManage(-Calculate::getEnergy(recipe));

}

void Cooking::Eat(EdibleUnit food){
    if (!StepChecker::CheckIngredient(food, kitchen.getUnits()))
        throw StepException("Eat failed: there is a lack of food");
    
        Date process(0, 0, 0, 0, 15, 0, false);
    if (!CookChecker::TimeToSleep(date, process))
        throw CookException("Eat failed: it's too late to eat for so long");
    
    Management manager(*this);

    manager.addTime(process);
    manager.removeIngredient(food);
    manager.EnergyManage(IngredientCalculate::getEnergy(food));

    manager.IncreaseEatenFood();
    manager.addEatenFoodByName(food.getName());
    manager.setDateLastEaten();
}

void Cooking::Sleep(){
    Management manager(*this);

    Date newD = date;
    newD += Date(0, 0, 1, 0, 0, 0, false);
    manager.untilTime(Date(newD.getYear(), newD.getMonth(), newD.getDay(), 7, 0, 0, true));
    manager.XPManage(-2);
    manager.EnergyManage(5);

    manager.IncreaseSleptNights();
}

void Cooking::WashDish(std::vector<std::unique_ptr<Utensil>>&& utensils, std::vector<std::unique_ptr<Tool>>&& tools)
{
    Dishwasher *unit = GetSomething::TakeThis<Dishwasher, KitchenUnit>(kitchen.getUnits());

    int timeCoeff{1};
    for (auto& u : utensils){
        if (timeCoeff < PurityHelper::getTimeCoeff(u->getClearStatus()))
            timeCoeff = PurityHelper::getTimeCoeff(u->getClearStatus());
    }
    for (auto& t : tools){
        if (timeCoeff < PurityHelper::getTimeCoeff(t->getClearStatus()))
            timeCoeff = PurityHelper::getTimeCoeff(t->getClearStatus());
    }

    unit->Wash(utensils, tools);

    Management manager(*this);

    manager.addTime(Date(0, 0, 0, 0, 20 * timeCoeff, 0, false));

    for (int i{0}; i < utensils.size(); i++)
        manager.IncreaseWashedUtils();

    for (int i{0}; i < tools.size(); i++)
        manager.IncreaseWashedTools();
    
    manager.setDateLastWash();
}

void Cooking::RemoveSpoiledFood()
{
    std::vector<Cupboard*> cupboards = GetSomething::TakeAllThis<Cupboard, KitchenUnit>(kitchen.getUnits());
    std::vector<Fridge*> fridges = GetSomething::TakeAllThis<Fridge, KitchenUnit>(kitchen.getUnits());

    for (auto& u: cupboards){
        RemoveSpoiledFood(*u);
    }
    for (auto& u: fridges){
        RemoveSpoiledFood(*u);
    }
}

void Cooking::AddRecipe(std::string& name, Recipe& recipe)
{
    if (cook.getXP() < CookLimits::XPforAddRecipe())
        throw XpException("Cooking failed: lack of experience");

    Management manager(*this);

    manager.addTime(Date(0, 0, 0, 0, 5, 0, false));
    manager.addRecipe(name, recipe);

    manager.IncreaseAddedRecipe();
    manager.setDateLastAddRecipe();
}

void Cooking::PickUPSupplier(Supplier& supplier)
{
    if (!CookChecker::CheckSupplier(cook.getName(), supplier, date))
        throw SupplierException("Supplier pick up failed: too frequent requests");
    
    Management manager(*this);

    for (auto i : supplier.getEdibleUnits())
        manager.addDish(std::move(std::make_unique<EdibleUnit>(i)));
    
    supplier.addSupplies(cook.getName(), date);
}

Person &Cooking::getCook()
{
    return cook;
}

const Kitchen &Cooking::getKitchen() const
{
    return kitchen;
}

const CookingBook &Cooking::getRecipes() const
{
    return recipes;
}

const Date &Cooking::getDate() const
{
    return date;
}

template<typename T>
void Cooking::RemoveSpoiledFood(StorageUnit<T>& unit)
{
    Management manager(*this);

    for (auto& i : unit.getUnits()){
        if (!CookChecker::CheckBestBeforeDate(date, *i)){
            Ingredient* ingredientPtr = i.get();
            manager.removeIngredient(*ingredientPtr);
            manager.IncreaseRemovedIngredient();
        }
    }

    manager.setDateLastRemoving();

};
