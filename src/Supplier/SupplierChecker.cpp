#include "SupplierChecker.h"
#include <iostream>

bool SupplierChecker::GetIngredients(std::string name, Supplier supplier, Date today)
{
    if (supplier.getSupplies().count(name) > 0){
        Date then = supplier.getSupplies()[name];
        then += supplier.getFrequency();

        return then < today;
    }
    return true;
}
