#pragma once
#include <stdexcept>
#include <string>

class HistoryException : public std::runtime_error {
public:
    explicit HistoryException(const std::string& msg) : std::runtime_error(msg) {}
};
