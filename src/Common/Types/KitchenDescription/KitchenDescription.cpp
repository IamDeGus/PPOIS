#include "KitchenDescription.h"



KitchenDescription::KitchenDescription(Size size, bool hasWater, bool hasPower,
                    bool hasGreaseTrap, bool climateZone,
                    const std::string& description)
                    :size(size), hasWater(hasWater),
                        hasPower(hasPower), hasGreaseTrap(hasGreaseTrap),
                        climateZone(climateZone), IDescription(description) {};

bool KitchenDescription::operator== (const KitchenDescription other) const
{
    return this->getDescription() == other.getDescription() &&
            this->size == other.size  &&
            this->hasWater == other.hasWater  &&
            this->hasPower == other.hasPower  &&
            this->hasGreaseTrap == other.hasGreaseTrap  &&
            this->climateZone == other.climateZone;        
}; 

Size KitchenDescription::getSize() const {return size;};

bool KitchenDescription::getHasWater() const {return hasWater;};
bool KitchenDescription::getHasPower() const {return hasPower;};
bool KitchenDescription::getHasGreaseTrap() const {return hasGreaseTrap;};
bool KitchenDescription::getClimateZone() const {return climateZone;};

