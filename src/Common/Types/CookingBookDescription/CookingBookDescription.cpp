#include "CookingBookDescription.h"


CookingBookDescription::CookingBookDescription(Grade grade, Certification certification,
                        const std::string& name, const std::string& description)
                        : grade(grade), certification(certification),
                            INameable(name), IDescription(description) {};

bool CookingBookDescription::operator== (const CookingBookDescription other) const{
    return this->certification == other.certification &&
            this->grade == other.grade &&
            this->getName() == other.getName() &&
            this->getDescription() == other.getDescription();
}

Grade CookingBookDescription::getGrade() const {return grade;};
Certification CookingBookDescription::getCertification() const {return certification;};

