#pragma once

#include <string>
#include <vector>

class RequiredData
{
private:
    std::vector<std::string> requiredTools;
    std::vector<std::string> requiredUtensils; 
    std::vector<std::string> requiredAppliances;

public:
    RequiredData(const std::vector<std::string>& tools,
                 const std::vector<std::string>& utensils,
                 const std::vector<std::string>& appliances);
    
    const std::vector<std::string>& getRequiredTools() const;
    const std::vector<std::string>& getRequiredUtensils() const;
    const std::vector<std::string>& getRequiredAppliances() const;
};
