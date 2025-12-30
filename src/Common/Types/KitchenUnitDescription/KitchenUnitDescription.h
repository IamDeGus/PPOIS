#pragma once

#include "../../I/IDescription.h"
#include "../../I/IDateCreate.h"
#include "../Date/Date.h"

#include "../Company/Company.h" 

class KitchenUnitDescription : public IDescription, public IDateCreate
{
private:
    int serialNumber;
    Company madeBy;
public:
    KitchenUnitDescription(int serialNumber, Company madeBy, const std::string& description,
                           const Date& dateCreate);

    bool operator== (const KitchenUnitDescription other) const;

    int getSerialNumber() const;
    Company getMadeBy() const;
};
