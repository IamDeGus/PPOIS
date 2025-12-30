#pragma once

#include <vector>
#include <memory>


class VectorConverter
{
public:
    template<typename Base, typename Derived>
    static std::vector<Base*> getRawPointers(const std::vector<std::unique_ptr<Derived>>& source) {
        static_assert(std::is_base_of<Base, Derived>::value,
                    "Derived must inherit from Base");
        
        std::vector<Base*> result;
        result.reserve(source.size());
        
        for (const auto& ptr : source) {
            result.push_back(ptr.get());
        }
        
        return result;
    }
};
