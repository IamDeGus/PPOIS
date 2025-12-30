#pragma once

#include <vector>
#include "StorageUnit.h"
#include "../../Tool/Tool.h"


class ToolStorage : public StorageUnit<Tool>
{
public:
    ToolStorage(std::vector<std::unique_ptr<Tool>> units, KitchenUnitDescription description, int capacity, std::string name) 
        : StorageUnit<Tool>(std::move(units), description, capacity, name) {};
};
