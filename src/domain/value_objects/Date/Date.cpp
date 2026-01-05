#include "Date.h"

Date::Date(int year, int month, int day){
    DateChecker check;
    if (check.CheckAll(year, month, day)){
        throw DateException("Date validation failed: incorrect calendar date");
    }

    year_ = year;
    month_ = month;
    day_ = day;
}

Date::Date()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    
    year_ = now->tm_year + 1900;
    month_ = now->tm_mon + 1;
    day_ = now->tm_mday;
}

bool Date::operator< (const Date other) const{
    if (this->year_ != other.year_)
        return this->year_ < other.year_;
    if (this->month_ != other.month_)
        return this->month_ < other.month_;
        
    return this->day_ < other.day_;
}

bool Date::operator>(const Date other) const
{
    if (this->year_ != other.year_)
        return this->year_ > other.year_;
    if (this->month_ != other.month_)
        return this->month_ > other.month_;
        
    return this->day_ > other.day_;
}

bool Date::operator== (const Date other) const{
    return this->year_ == other.year_     &&
           this->month_ == other.month_   &&
           this->day_ == other.day_;
}

bool Date::operator!=(const Date other) const
{
    return this->year_ != other.year_     ||
           this->month_ != other.month_   ||
           this->day_ != other.day_;
}

int Date::getYear() const{
    return year_;
}

int Date::getMonth() const{
    return month_;
}

int Date::getDay() const{
    return day_;
}
