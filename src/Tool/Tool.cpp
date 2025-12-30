#include "Tool.h"

Tool::Tool(std::string name, StateOfPurity clearStatus, bool isSharp) 
        : INameable(name), clearStatus(clearStatus), isSharp(isSharp) {};

StateOfPurity Tool::getClearStatus() const
{
    return clearStatus;
}
bool Tool::getIsSharp() const
{
    return isSharp;
};

bool Tool::operator== (const Tool other) const{
    return this->getName() == other.getName();
}
 

void Tool::Dish() {
    clearStatus = StateOfPurity::Clear;
};

void Tool::GetDirty(StateOfPurity newStatus){
    clearStatus = newStatus;
};
