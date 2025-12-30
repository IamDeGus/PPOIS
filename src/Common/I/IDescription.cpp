#include "IDescription.h"

IDescription::IDescription(std::string description) : description(description) {};

std::string IDescription::getDescription() const {return description;};
