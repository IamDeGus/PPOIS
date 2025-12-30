#pragma once


class DateChecker
{
public:
    bool CheckYear(int year);
    bool CheckMonth(int month);
    bool CheckDay(int day);

    bool CheckHour(int hour);
    bool CheckMinSec(int min_sec);

    bool CheckAll(int year, int month, int day, int hour, int min, int sec);
};
