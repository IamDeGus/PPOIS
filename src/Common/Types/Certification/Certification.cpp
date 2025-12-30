#include "Certification.h"


Certification::Certification(const std::string& name, const std::string& description)
    : INameable(name), IDescription(description) {};

bool Certification::operator== (const Certification other) const{
    return this->getName() == other.getName() &&
            this->getDescription() == other.getDescription();
}
