#pragma once
#include <stdexcept>
#include <string>

class DateException : public std::runtime_error {
public:
    explicit DateException(const std::string& msg) : std::runtime_error(msg) {}
};
