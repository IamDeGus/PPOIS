#include "RequiredData.h"

RequiredData::RequiredData(const std::vector<std::string> &tools, 
                           const std::vector<std::string> &utensils,
                           const std::vector<std::string> &appliances)
    : requiredTools(tools), requiredUtensils(utensils), requiredAppliances(appliances) {}

const std::vector<std::string>& RequiredData::getRequiredTools() const {
    return requiredTools;
}

const std::vector<std::string>& RequiredData::getRequiredUtensils() const {
    return requiredUtensils;
}

const std::vector<std::string>& RequiredData::getRequiredAppliances() const {
    return requiredAppliances;
}
