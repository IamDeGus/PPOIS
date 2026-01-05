#pragma once
#include <stdexcept>
#include <string>

class AgesException : public std::runtime_error {
public:
    explicit AgesException(const std::string& msg) : std::runtime_error(msg) {}
};
