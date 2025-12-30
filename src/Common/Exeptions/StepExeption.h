#pragma once
#include <stdexcept>
#include <string>

class StepException : public std::runtime_error {
public:
    explicit StepException(const std::string& msg) : std::runtime_error(msg) {}
};
