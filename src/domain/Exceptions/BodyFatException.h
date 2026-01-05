#pragma once
#include <stdexcept>
#include <string>

class BodyFatException : public std::runtime_error {
public:
    explicit BodyFatException(const std::string& msg) : std::runtime_error(msg) {}
};
