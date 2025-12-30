#pragma once

#include "../../I/IDescription.h"
#include "../Size/Size.h"

class KitchenDescription : public IDescription
{
private:
    Size size;

    bool hasWater;
    bool hasPower;
    bool hasGreaseTrap;
    bool climateZone;
public:
    KitchenDescription(Size size, bool hasWater, bool hasPower,
                       bool hasGreaseTrap, bool climateZone,
                       const std::string& description);

    bool operator== (const KitchenDescription other) const; 

    Size getSize() const;

    bool getHasWater() const;
    bool getHasPower() const;
    bool getHasGreaseTrap() const;
    bool getClimateZone() const;
};
