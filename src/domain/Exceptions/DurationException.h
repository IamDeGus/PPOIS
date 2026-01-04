#pragma once
#include <stdexcept>
#include <string>

class DurationException : public std::runtime_error {
public:
    explicit DurationException(const std::string& msg) : std::runtime_error(msg) {}
};
