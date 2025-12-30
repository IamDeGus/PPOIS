#pragma once 

#include <string>

class IDescription
{
private:
    std::string description;
public:
    IDescription(std::string description);
    virtual ~IDescription() = default;

    std::string getDescription() const; 
};
