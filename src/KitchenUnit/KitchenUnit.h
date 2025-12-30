#pragma once

#include "../Common/I/INameable.h"
#include "../Common/Types/KitchenUnitDescription/KitchenUnitDescription.h"

class KitchenUnit : public INameable
{
private:
    KitchenUnitDescription description;
public:
    KitchenUnit(std::string name, KitchenUnitDescription description);
    virtual ~KitchenUnit() = default;

    bool operator== (const KitchenUnit other) const;

    KitchenUnitDescription getDescription() const;
};
