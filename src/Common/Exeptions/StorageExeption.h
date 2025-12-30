#pragma once
#include <stdexcept>
#include <string>

class StorageException : public std::runtime_error {
public:
    explicit StorageException(const std::string& msg) : std::runtime_error(msg) {}
};
