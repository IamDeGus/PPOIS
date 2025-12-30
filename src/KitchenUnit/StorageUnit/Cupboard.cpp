#include "Cupboard.h"

int Cupboard::getCapacityUsed() const
{
    float total{0};
    for (auto& u: items){
        total += IngredientCalculate::getVolumeCapacity(*u);
    }
    total += 1;
    return int(total);
}


void Cupboard::addItem(std::unique_ptr<Ingredient> unit)
{
    for (auto& i: items){
        if (i->getName() == unit->getName()){
            Liquid* liquidPtr = dynamic_cast<Liquid*>(unit.get());
            float density{1};
            if (liquidPtr != nullptr)
                density = liquidPtr->getDensity();
            unit->getWeightt().ConventerTo(i->getWeight().getMeasur(), density);
            i->getWeightt() += unit->getWeightt();
            return;
        }
    }
    items.push_back(std::move(unit));
}

void Cupboard::removeItem(Ingredient* unit)
{
    for (auto& i: items){
        if (i->getName() == unit->getName()){
            Liquid* liquidPtr = dynamic_cast<Liquid*>(unit);
            float density{1};
            if (liquidPtr != nullptr)
                density = liquidPtr->getDensity();
            unit->getWeightt().ConventerTo(i->getWeight().getMeasur(), density);
            i->getWeightt() -= unit->getWeightt();
            return;
        }
    }
    throw StorageException("Item remove failed: item not found");
}
