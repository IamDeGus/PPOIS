#pragma once
#include <stdexcept>
#include <string>

class SupplierException : public std::runtime_error {
public:
    explicit SupplierException(const std::string& msg) : std::runtime_error(msg) {}
};
