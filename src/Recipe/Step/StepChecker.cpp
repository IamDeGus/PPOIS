#include "StepChecker.h"


bool StepChecker::CheckKitchenUnit(std::string name, const std::vector<std::unique_ptr<KitchenUnit>>& units){
    for (auto& u : units){
        if (name == u->getName())
            return true;
    }
    return false;
}

bool StepChecker::CheckTool(std::string name, const std::vector<std::unique_ptr<KitchenUnit>>& units){
    if (!CheckKitchenUnit("ToolStorage", units))
        return false;
    

    ToolStorage *temp = GetSomething::TakeThis<ToolStorage, KitchenUnit>(units);
    
    for (auto& t : temp->getUnits()){
        if (name == t->getName())
            return true;
    }
    return false;
}

bool StepChecker::CheckUtensil(std::string name, const std::vector<std::unique_ptr<KitchenUnit>>& units){
    if (!CheckKitchenUnit("UtensilStorage", units))
        return false;

    UtensilStorage *temp = GetSomething::TakeThis<UtensilStorage, KitchenUnit>(units);
    
    for (auto& t : temp->getUnits()){
        if (name == t->getName())
            return true;
    }
    return false;
}

bool StepChecker::CheckIngredient(const Ingredient& ingredient, const std::vector<std::unique_ptr<KitchenUnit>>& units){
    Temperature t{Temperature::Cool};

    const EdibleUnit* temp = dynamic_cast<const EdibleUnit*>(&ingredient);
    if (temp != nullptr){
        t = temp->getT();
    }

    if (t == Temperature::Cool){
        Cupboard *cupboard = GetSomething::TakeThis<Cupboard, KitchenUnit>(units);
        return CheckIngredient(ingredient, VectorConverter::getRawPointers<Ingredient, Ingredient>(cupboard->getUnits()));
    } else if (t == Temperature::Freezing || t == Temperature::Cold){
        std::vector<Fridge*> fridge = GetSomething::TakeAllThis<Fridge, KitchenUnit>(units);
        for (auto& f : fridge){
            if (f->getT() == t){
                if (CheckIngredient(ingredient, VectorConverter::getRawPointers<Ingredient, EdibleUnit>(f->getUnits())))
                    return true;
            }
        }
    }

    return false;
}

bool StepChecker::CheckIngredient(const Ingredient &ingredient, const std::vector<Ingredient*>& units){
    for (auto& i : units){
        if (ingredient.getName() == i->getName()){
            Weight weight = i->getWeight();

            if (weight.getMeasur() != ingredient.getWeight().getMeasur()){
                if (typeid(*i) == typeid(Liquid)){
                    Liquid& format_i = dynamic_cast<Liquid&>(*i);
                    weight.ConventerMeTo(ingredient.getWeight().getMeasur(), format_i.getDensity());
                } else{
                    weight.ConventerMeTo(ingredient.getWeight().getMeasur());
                }
            }

            if (ingredient.getWeight() < (weight + Weight(0.0001, weight.getMeasur())))
                return true;
            
            return false;
        }
    }
    return false;
}

bool StepChecker::CheckPurityStatus(std::string utensil, std::string tool, const std::vector<std::unique_ptr<KitchenUnit>> &units)
{
    UtensilStorage *tempU = GetSomething::TakeThis<UtensilStorage, KitchenUnit>(units);
    
    bool utensilB{false};
    for (auto& t : tempU->getUnits()){
        if (utensil == t->getName()){
            if (t->getClearStatus() == StateOfPurity::Dirty)
                return false;
            else {
                utensilB = true;
                break;
            }
        }
    }

    if (!utensilB)
        return false;
    

    ToolStorage *tempT = GetSomething::TakeThis<ToolStorage, KitchenUnit>(units);
    
    for (auto& t : tempT->getUnits()){
        if (tool == t->getName()){
            if (t->getClearStatus() == StateOfPurity::Dirty)
                return false;
            else
                return true;
        }
    }

    return false;
}
