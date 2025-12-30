#pragma once
#include <stdexcept>
#include <string>

class CookException : public std::runtime_error {
public:
    explicit CookException(const std::string& msg) : std::runtime_error(msg) {}
};
