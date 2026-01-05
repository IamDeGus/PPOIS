#pragma once

#include "../../Interfaces/IMetricHistory.h"
#include "../../Exceptions/HistoryException.h"
#include <algorithm>
#include <vector>
#include <iterator>


template<typename T>
class MetricHistory : public IMetricHistory<T>
{
private:
    std::map<Date, T> history_;
public:
    void addRecord(T value) override{
        history_[Date()] = value;
    };

    void addRecord(T value, Date date) override{
        history_[date] = value;
    };

    std::optional<T> tryGet(Date date) const noexcept override{
        auto it = history_.find(date);
        return it != history_.end() ? std::optional<T>(it->second) : std::nullopt;
    }

    T get(Date date) const override{
        if (history_.count(date) == 0)
            throw HistoryException("Get value failed: no exist");
        return history_[date];
    };

    std::map<Date, T> getRange(Date from, Date to) const override{
        if (!(from < to))
            throw HistoryException("Get values failed: inccorect input");
        
        std::map<Date, T> result;

        auto it_begin = history_.upper_bound(from);
        auto it_end = history_.upper_bound(to);
        
        result.insert(it_begin, it_end);
        
        return result;
    };

    std::map<Date, T> getLastNDays(int n) const override{
        std::map<Date, T> result;

        auto it_end = history_.end();
        auto it_begin = history_.end();
        advance(it_begin, -n);
        
        result.insert(it_begin, it_end);
        
        return result; 
    };

    std::vector<Date> getAvailableDates() const override{
        std::vector<Date> result;
        result.reserve(history_.size());

        std::transform(
            history_.begin(), history_.end(),
            std::back_inserter(result),
            [](const auto& pair) {
                return pair.first;
            });
        
        return result;
    };

    size_t size() const override{
        return history_.size();
    };


};

