#include "DateChecker.h"


bool DateChecker::CheckYear(int year){
    return year < 2100 && year > 1900;
}

bool DateChecker::CheckMonth(int month){
    return month <= 12 && month >= 1;
}

bool DateChecker::CheckDay(int day, int month, int year){
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        daysInMonth[1] = 29;
    }

    return day >= 1 && day <= daysInMonth[month-1];
}

bool DateChecker::CheckAll(int year, int month, int day){
    return CheckYear(year)     &&
           CheckMonth(month)   &&
           CheckDay(day, month, year);
}
