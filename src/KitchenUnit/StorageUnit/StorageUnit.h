#pragma once

#include <vector>
#include "../KitchenUnit.h"
#include "../../Tool/Tool.h"
#include "../../Common/Types/Weight/Weight.h"
#include "../../Common/GetSomething/GetSomething.h"
#include "../../Common/I/INameable.h"
#include "../../Common/Exeptions/StorageExeption.h"

class Management;


template<typename T>
class StorageUnit : public KitchenUnit
{
protected:
    std::vector<std::unique_ptr<T>> items;
    int capacity;

public:
    StorageUnit() = default;
    StorageUnit(std::vector<std::unique_ptr<T>> items, KitchenUnitDescription description,  int capacity, std::string name)
        : KitchenUnit(name, description), items(std::move(items)), capacity(capacity) {};
    ~StorageUnit() = default;

    StorageUnit(const StorageUnit&) = delete;
    StorageUnit& operator=(const StorageUnit&) = delete;
    
    StorageUnit(StorageUnit&&) = default;
    StorageUnit& operator=(StorageUnit&&) = default;

    virtual int getCapacityUsed() const
    {
        return  items.size();
    };
    virtual int getCapacityTotal() const{
        return capacity;
    };

    std::vector<std::unique_ptr<T>>& getUnits()
    {
        return items;
    };

protected:
    virtual void addItem(std::unique_ptr<T> item)
    {
        items.push_back(std::move(item));
    };

    virtual void removeItem(T* item)
    {
        std::string targetName = item->getName();
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getName() == targetName) {
                items.erase(it);
                return;
            }
        }
        throw StorageException("Item remove failed: item not found");
    };

    friend class Management;
};
