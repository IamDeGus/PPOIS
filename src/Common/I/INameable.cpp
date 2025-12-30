#include "INameable.h"


INameable::INameable(std::string name) : name(name) {};

std::string INameable::getName() const {return name;}; 
