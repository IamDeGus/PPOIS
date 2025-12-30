#pragma once 

#include "../Types/Date/Date.h"

class IDateCreate
{
private:
    Date create;
public:
    IDateCreate(Date create);
    virtual ~IDateCreate() = default;

    Date getDateCreate() const; 
};
