#include "Supplier.h"

Supplier::Supplier(Company company, std::vector<EdibleUnit> edibleUnits,
                   std::map<std::string, Date> supplies, Date frequency,
                   const std::string &name) 
                   : company(company), edibleUnits(edibleUnits),
                     supplies(supplies), frequency(frequency),
                     INameable(name) {}

Company Supplier::getCompany() const
{
    return company;
}

std::vector<EdibleUnit> Supplier::getEdibleUnits() const
{
    return edibleUnits;
}

std::map<std::string, Date> Supplier::getSupplies() const
{
    return supplies;
}

Date Supplier::getFrequency() const
{
    return frequency;
}

void Supplier::addSupplies(std::string person, Date today)
{
    supplies[person] = today;
}
