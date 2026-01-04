#pragma once
#include <stdexcept>
#include <string>

class CaloriesException : public std::runtime_error {
public:
    explicit CaloriesException(const std::string& msg) : std::runtime_error(msg) {}
};
