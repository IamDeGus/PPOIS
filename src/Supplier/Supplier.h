#pragma once

#include <vector>
#include <map>

#include "../Common/Types/Company/Company.h"
#include "../Common/I/INameable.h"
#include "../Common/Types/Date/Date.h"
#include "../Ingredient/EdibleUnit.h"

class Management;
class Cooking;

class Supplier : public INameable
{
private:
    Company company;

    std::vector<EdibleUnit> edibleUnits;
    std::map<std::string, Date> supplies;
    Date frequency;
public:
    Supplier(Company company, std::vector<EdibleUnit> edibleUnits,
             std::map<std::string, Date> supplies, Date frequency, 
             const std::string& name);
    

    Company getCompany() const;

    std::vector<EdibleUnit> getEdibleUnits() const;
    std::map<std::string, Date> getSupplies() const;
    Date getFrequency() const;

protected:
    void addSupplies(std::string person, Date today);

    friend class Cooking;
    friend class Management;
};
