#pragma once
#include <stdexcept>
#include <string>

class MacrosException : public std::runtime_error {
public:
    explicit MacrosException(const std::string& msg) : std::runtime_error(msg) {}
};
