#pragma once

#include "StorageUnit.h"


class StorageChecker
{
public:
    template<typename T>
    static bool CheckCapacity(StorageUnit<T> unit, int capacity)
    {
        return capacity < unit.getCapacityTotal();
    };
};
