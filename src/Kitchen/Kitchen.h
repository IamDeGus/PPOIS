#pragma once


#include <vector>
#include <memory>

#include "../KitchenUnit/KitchenUnit.h"
#include "../Common/Types/Date/Date.h"

#include "../Common/Types/KitchenDescription/KitchenDescription.h"

class Kitchen
{
private:
    std::vector<std::unique_ptr<KitchenUnit>> units;

    KitchenDescription description;

public:
    Kitchen(std::vector<std::unique_ptr<KitchenUnit>> units, KitchenDescription description);

    Kitchen(const Kitchen&) = delete;
    Kitchen& operator=(const Kitchen&) = delete;
    
    Kitchen(Kitchen&&) = default;
    Kitchen& operator=(Kitchen&&) = default;

    const std::vector<std::unique_ptr<KitchenUnit>>& getUnits() const;
    KitchenDescription getDescription() const;
};
