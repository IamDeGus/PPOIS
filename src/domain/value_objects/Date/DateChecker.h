#pragma once


class DateChecker
{
public:
    bool CheckYear(int year);
    bool CheckMonth(int month);
    bool CheckDay(int day, int month, int year);

    bool CheckAll(int year, int month, int day);
};
