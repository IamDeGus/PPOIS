#include "BodyFatCategory.h"

BodyFatCategory::BodyFatCategory(FatCategory category)
    : category_(category) {}

std::string BodyFatCategory::toString()
{
    switch (category_)
    {
    case FatCategory::underweight:
        return "Underweight";
    case FatCategory::normal:
        return "Normal";
    case FatCategory::overweight:
        return "Overweight";
    case FatCategory::obesity:
        return "Obesity";
    }
}

FatCategory BodyFatCategory::getCategory() const
{
    return category_;
}

std::string BodyFatCategory::getDescription() const
{
    return description_;
}
