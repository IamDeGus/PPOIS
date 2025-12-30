#pragma once
#include <stdexcept>
#include <string>

class XpException : public std::runtime_error {
public:
    explicit XpException(const std::string& msg) : std::runtime_error(msg) {}
};
