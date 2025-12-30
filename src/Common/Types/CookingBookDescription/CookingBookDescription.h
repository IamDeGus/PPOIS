#pragma once

#include "../../I/INameable.h"
#include "../../I/IDescription.h"
#include "../Grade/Grade.h"
#include "../Certification/Certification.h"

class CookingBookDescription : public INameable, public IDescription
{
private:
    Grade grade;
    Certification certification;
public:
    CookingBookDescription(Grade grade, Certification certification,
                           const std::string& name, const std::string& description);

    bool operator== (const CookingBookDescription other) const;

    Grade getGrade() const;
    Certification getCertification() const;
};
