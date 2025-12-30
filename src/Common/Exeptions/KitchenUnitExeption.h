#pragma once
#include <stdexcept>
#include <string>

class KitchenUnitException : public std::runtime_error {
public:
    explicit KitchenUnitException(const std::string& msg) : std::runtime_error(msg) {}
};
