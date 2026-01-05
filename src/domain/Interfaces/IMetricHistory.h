#pragma once

#include "../value_objects/Date/Date.h"
#include <optional>
#include <map>

template<typename T>
class IMetricHistory {
public:
    virtual void addRecord(T value) = 0;
    virtual void addRecord(T value, Date date) = 0;

    virtual std::optional<T> tryGet(Date date) const noexcept = 0;
    virtual T get(Date date) const = 0;

    virtual std::map<Date, T> getRange(Date from, Date to) const = 0;
    virtual std::map<Date, T> getLastNDays(int n) const = 0;

    virtual std::vector<Date> getAvailableDates() const = 0;

    virtual ~IMetricHistory() = default;

    virtual size_t size() const = 0;
};
