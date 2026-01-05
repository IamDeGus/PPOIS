#pragma once

#include <ctime>
#include "DateChecker.h"
#include "../../Exceptions/DateException.h"

class Date
{
private:
    int day_;
    int month_;
    int year_;

public:
    Date(int year, int month, int day);
    Date();


    bool operator< (const Date other) const;
    bool operator> (const Date other) const;
    bool operator== (const Date other) const;
    bool operator!= (const Date other) const;

    int getYear() const;
    int getMonth() const;
    int getDay() const;

};
