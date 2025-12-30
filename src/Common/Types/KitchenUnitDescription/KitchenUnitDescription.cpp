#include "KitchenUnitDescription.h"


KitchenUnitDescription::KitchenUnitDescription(int serialNumber, Company madeBy, const std::string& description,
                        const Date& dateCreate)
                        : serialNumber(serialNumber), madeBy(madeBy),
                            IDescription(description), IDateCreate(dateCreate) {};

bool KitchenUnitDescription::operator== (const KitchenUnitDescription other) const{
    return this->getDateCreate() == other.getDateCreate() &&
            this->getDescription() == other.getDescription() &&
            this->serialNumber == other.serialNumber &&
            this->madeBy == other.madeBy;
};

int KitchenUnitDescription::getSerialNumber() const {return serialNumber;};
Company KitchenUnitDescription::getMadeBy() const {return madeBy;};
