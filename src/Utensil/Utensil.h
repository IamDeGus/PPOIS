#pragma once

#include "../Common/I/INameable.h"
#include "../Common/Types/StateOfPurity/StateOfPurity.h"

class Management;

class Utensil : public INameable
{
private:
    StateOfPurity clearStatus;
    bool isHeatResistant;
public:
    Utensil(std::string name, StateOfPurity clearStatus = StateOfPurity::Clear, bool isHeatResistant = false);

    StateOfPurity getClearStatus() const;
    bool getIsHeatResistant() const;

    bool operator== (const Utensil other) const;

protected:
    void Dish();

    void GetDirty(StateOfPurity newStatus);

    friend class Management;
    friend class Dishwasher;
};
