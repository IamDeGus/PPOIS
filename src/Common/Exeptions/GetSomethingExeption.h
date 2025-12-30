#pragma once
#include <stdexcept>
#include <string>

class GetSomethingException : public std::runtime_error {
public:
    explicit GetSomethingException(const std::string& msg) : std::runtime_error(msg) {}
};
