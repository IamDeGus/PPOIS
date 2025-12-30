#pragma once

#include "../../I/IDescription.h"
#include "../../I/INameable.h"

class Certification : public IDescription, public INameable
{
public:
    Certification(const std::string& name, const std::string& description);

    bool operator== (const Certification other) const;
};
