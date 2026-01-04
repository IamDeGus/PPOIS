#pragma once
#include <stdexcept>
#include <string>

class CircumferenceException : public std::runtime_error {
public:
    explicit CircumferenceException(const std::string& msg) : std::runtime_error(msg) {}
};
