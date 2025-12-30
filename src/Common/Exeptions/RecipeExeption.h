#pragma once
#include <stdexcept>
#include <string>

class RecipeException : public std::runtime_error {
public:
    explicit RecipeException(const std::string& msg) : std::runtime_error(msg) {}
};
