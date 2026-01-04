#pragma once
#include <stdexcept>
#include <string>

class HeightException : public std::runtime_error {
public:
    explicit HeightException(const std::string& msg) : std::runtime_error(msg) {}
};
