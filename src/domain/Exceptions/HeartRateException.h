#pragma once
#include <stdexcept>
#include <string>

class HeartRateException : public std::runtime_error {
public:
    explicit HeartRateException(const std::string& msg) : std::runtime_error(msg) {}
};
