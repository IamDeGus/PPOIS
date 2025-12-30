#include "IDateCreate.h"

IDateCreate::IDateCreate(Date create) : create(create) {};

Date IDateCreate::getDateCreate() const {return create;}; 
