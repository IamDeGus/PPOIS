#include "Date.h"
#include "DateChecker.h"
#include "../Exeptions/DateExeption.h"


Date::Date(int year, int month, int day,
           int hour, int min, int sec, bool calendar){
    DateChecker check;
    if (calendar && !check.CheckAll(year, month, day, hour, min, sec)){
        throw DateException("Date validation failed: incorrect calendar date");
    }

    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->min = min;
    this->sec = sec;
    this->calendar = calendar;

}

long Date::ConvertToSec() const{
    return (((((year * 12 + month) * 30) + day) * 24 + hour) * 60 + min) * 60 + sec;
}

bool Date::operator< (const Date other) const{
    if (this->calendar != other.calendar){
        throw DateException("Date comparison failed:  can't compare a calendar date and a non-calendar date");
    }
    if (this->calendar){
        if (this->year != other.year)
            return this->year < other.year;
        
        if (this->month != other.month)
            return this->month < other.month;

        if (this->day != other.day)
            return this->day < other.day;

        if (this->hour != other.hour)
            return this->hour < other.hour;

        if (this->min != other.min)
            return this->min < other.min;
        
        return this->sec < other.sec;
    }else{
        long k1, k2;
        k1 = this->ConvertToSec();
        k2 = other.ConvertToSec();
        return k1 < k2;
    }
}

bool Date::operator== (const Date other) const{
    if (this->calendar != other.calendar){
        throw DateException("Date comparison failed: can't compare a calendar date and a non-calendar date");
    }
    if (this->calendar){
        return this->year == other.year     &&
               this->month == other.month   &&
               this->day == other.day       &&
               this->hour == other.hour     &&
               this->min == other.min       &&
               this->sec == other.sec;
    } else {
        long k1, k2;
        k1 = this->ConvertToSec();
        k2 = other.ConvertToSec();
        return k1 == k2;
    }
}

Date& Date::operator+= (const Date other){
    if (other.calendar){
        throw DateException("Date addition failed: can't add calendar dates together");
    }

    if (this->calendar){
        long k;
        k = other.ConvertToSec();

        k += this->sec;     this->sec   =  k % 60; k /= 60;
        k += this->min;     this->min   =  k % 60; k /= 60;
        k += this->hour;    this->hour  =  k % 24; k /= 24;
        k += this->day;     this->day   =  k % 30; k /= 30;
        k += this->month;   this->month =  k % 12; k /= 12;
        this->year  +=  k;

        return *this;
    } else{
        long k1, k2;
        k1 = this->ConvertToSec();
        k2 = other.ConvertToSec();
        Date result(0, 0, 0, 0, 0, k1+k2, false);
        *this = result;
        return *this;
    }

}

Date &Date::operator=(const Date other){
    if (this->calendar != other.calendar){
        throw DateException("Date assignment failed: can't assignment a calendar date and a non-calendar date");
    }
    this->sec   = other.sec;
    this->min   = other.min;
    this->hour  = other.hour;
    this->day   = other.day;
    this->month = other.month;
    this->year  = other.year;
    return *this;
}

int Date::getYear() const{
    return year;
}

int Date::getMonth() const{
    return month;
}

int Date::getDay() const{
    return day;
}

int Date::getHour() const{
    return hour;
}

int Date::getMin() const{
    return min;
}

int Date::getSec() const{
    return sec;
}



