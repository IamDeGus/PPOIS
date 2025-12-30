#pragma once

#include "../Common/I/INameable.h"
#include "../Common/Types/StateOfPurity/StateOfPurity.h"

class Management;

class Tool : public INameable
{
private:
    StateOfPurity clearStatus{StateOfPurity::Clear};
    bool isSharp;

public:
    Tool(std::string name, StateOfPurity clearStatus = StateOfPurity::Clear, bool isSharp = false);

    StateOfPurity getClearStatus() const;
    bool getIsSharp() const;

    bool operator== (const Tool other) const;
    
protected:
    void Dish();

    void GetDirty(StateOfPurity newStatus);

    friend class Management;
    friend class Dishwasher;
};
