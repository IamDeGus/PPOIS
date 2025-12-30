#pragma once

#include "Supplier.h"

class SupplierChecker
{
public:
    static bool GetIngredients(std::string name, Supplier supplier, Date today);

};
