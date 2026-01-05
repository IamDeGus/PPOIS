#pragma once
#include <stdexcept>
#include <string>

class FitnessLevelException : public std::runtime_error {
public:
    explicit FitnessLevelException(const std::string& msg) : std::runtime_error(msg) {}
};
