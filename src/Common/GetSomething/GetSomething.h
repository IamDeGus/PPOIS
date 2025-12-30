#pragma once

#include <vector>
#include <memory>
#include "../Exeptions/GetSomethingExeption.h"

class GetSomething
{
public:
    template<typename DerivedType, typename BaseType>
    static DerivedType* TakeThis(const std::vector<std::unique_ptr<BaseType>>& objs){
        for (const auto& o : objs){
            if (auto p = dynamic_cast<DerivedType*>(o.get()))
                return p;
        }
        throw GetSomethingException("Object retrieval failed: object not found");
    };

    template<typename DerivedType, typename BaseType>
    static std::vector<DerivedType*> TakeAllThis(const std::vector<std::unique_ptr<BaseType>>& objs){
        std::vector<DerivedType*> result;
        for (const auto& o : objs){
            if (auto p = dynamic_cast<DerivedType*>(o.get()))
                result.push_back(p);
        }
        return result;
    };
};
