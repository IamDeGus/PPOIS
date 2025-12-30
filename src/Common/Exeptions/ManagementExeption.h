#pragma once
#include <stdexcept>
#include <string>

class ManagementException : public std::runtime_error {
public:
    explicit ManagementException(const std::string& msg) : std::runtime_error(msg) {}
};
