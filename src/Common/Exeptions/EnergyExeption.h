#pragma once
#include <stdexcept>
#include <string>

class EnergyException : public std::runtime_error {
public:
    explicit EnergyException(const std::string& msg) : std::runtime_error(msg) {}
};
