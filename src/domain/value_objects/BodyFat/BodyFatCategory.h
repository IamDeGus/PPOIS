#pragma once

#include <string>

enum class FatCategory{
    underweight,
    normal,
    overweight,
    obesity
};

class BodyFatCategory
{
private:
    FatCategory category_;
    std::string description_;
public:
    BodyFatCategory(FatCategory category);

    std::string toString();

    FatCategory getCategory() const;
    std::string getDescription() const;
};
