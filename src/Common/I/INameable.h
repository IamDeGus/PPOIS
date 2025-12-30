#pragma once

#include <string>

class INameable
{
private:
    std::string name;
public:
    INameable(std::string name);
    virtual ~INameable() = default;

    std::string getName() const; 
};
