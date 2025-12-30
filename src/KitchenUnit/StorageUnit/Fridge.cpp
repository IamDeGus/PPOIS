#include "Fridge.h"


int Fridge::getCapacityUsed() const {
    float total{0};
    for (auto& u: items){
        total += IngredientCalculate::getVolumeCapacity(*u);
    }
    total += 1;
    return int(total);
}

Temperature Fridge::getT() const
{
    return t;
}

void Fridge::addItem(std::unique_ptr<EdibleUnit> unit)
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

void Fridge::removeItem(EdibleUnit* unit)
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
