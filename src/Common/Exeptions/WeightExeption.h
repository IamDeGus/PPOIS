#pragma once
#include <stdexcept>
#include <string>

class WeightException : public std::runtime_error {
public:
    explicit WeightException(const std::string& msg) : std::runtime_error(msg) {}
};
