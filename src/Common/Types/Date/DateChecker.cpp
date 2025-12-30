#include "DateChecker.h"


bool DateChecker::CheckYear(int year){
    return year < 2026 && year > 1900;
}

bool DateChecker::CheckMonth(int month){
    return month <= 12 && month >= 1;
}

bool DateChecker::CheckDay(int day){
    return day <= 30 && day >= 1;
}

bool DateChecker::CheckHour(int hour){
    return hour < 24 && hour >= 0;
}

bool DateChecker::CheckMinSec(int min_sec){
    return min_sec < 60 && min_sec >= 0;
}


bool DateChecker::CheckAll(int year, int month, int day, int hour, int min, int sec){
    return CheckYear(year)     &&
           CheckMonth(month)   &&
           CheckDay(day)       &&
           CheckHour(hour)     &&
           CheckMinSec(min)    &&
           CheckMinSec(sec);
}
