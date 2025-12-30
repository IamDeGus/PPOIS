#pragma once


class Date
{
private:
    int day, month, year, hour, min, sec;

    bool calendar;
public:
    Date(int year = 2025, int month = 1, int day = 1,
         int hour = 0, int min = 0, int sec = 0, bool calendar = true);
    
    long ConvertToSec() const;
    
    bool operator< (const Date other) const;
    bool operator== (const Date other) const;

    Date& operator+= (const Date other);
    Date& operator= (const Date other);

    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMin() const;
    int getSec() const;

};

