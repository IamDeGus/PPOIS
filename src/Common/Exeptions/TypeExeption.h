#pragma once
#include <stdexcept>
#include <string>

class TypeException : public std::runtime_error {
public:
    explicit TypeException(const std::string& msg) : std::runtime_error(msg) {}
};
