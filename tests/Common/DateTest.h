#include <UnitTest++/UnitTest++.h>

#include "../../src/Common/Types/Date/Date.h"
#include "../../src/Common/Exeptions/DateExeption.h"

SUITE(DateTest)
{
    TEST(Date_ConstructorAndGetters)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(0, 0, 20, 0, 0, 0, false);

        CHECK_EQUAL(2020, date1.getYear());
        CHECK_EQUAL(7, date1.getMonth());
        CHECK_EQUAL(15, date1.getDay());
        CHECK_EQUAL(18, date1.getHour());
        CHECK_EQUAL(30, date1.getMin());
        CHECK_EQUAL(56, date1.getSec());

        CHECK_EQUAL(0, date2.getYear());
        CHECK_EQUAL(0, date2.getMonth());
        CHECK_EQUAL(20, date2.getDay());
        CHECK_EQUAL(0, date2.getHour());
        CHECK_EQUAL(0, date2.getMin());
        CHECK_EQUAL(0, date2.getSec());
    }


    TEST(Date_CalendarLess1)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(2021, 8, 16, 19, 31, 57, true);

        CHECK_EQUAL(true, date1 < date2);
    }

    TEST(Date_CalendarLess2)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(2020, 8, 16, 19, 31, 57, true);

        CHECK_EQUAL(true, date1 < date2);
    }

    TEST(Date_CalendarLess3)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(2020, 7, 16, 19, 31, 57, true);

        CHECK_EQUAL(true, date1 < date2);
    }

    TEST(Date_CalendarLess4)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(2020, 7, 15, 19, 31, 57, true);

        CHECK_EQUAL(true, date1 < date2);
    }

    TEST(Date_CalendarLess5)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(2020, 7, 15, 18, 31, 57, true);

        CHECK_EQUAL(true, date1 < date2);
    }

    TEST(Date_CalendarLess6)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(2020, 7, 15, 18, 30, 57, true);

        CHECK_EQUAL(true, date1 < date2);
    }

    TEST(Date_NoCalendarLess)
    {
        Date date1(0, 0, 7, 0, 0, 0, false);
        Date date2(0, 0, 6, 25, 0, 0, false);

        CHECK_EQUAL(true, date1 < date2);
    }

    TEST(Date_Addition)
    {
        Date date1(0, 0, 0, 0, 1, 0, false);
        Date date2(0, 0, 0, 0, 0, 30, false);

        date1 += date2;

        CHECK_EQUAL(90, date1.getSec());
    }

    TEST(Date_Exception)
    {
        Date date1(2020, 7, 15, 18, 30, 56, true);
        Date date2(2021, 8, 16, 19, 31, 57, true);
        Date date3(0, 0, 0, 0, 1, 0, false);
        Date date4(0, 0, 0, 0, 0, 30, false);

        CHECK_THROW(Date(2020, 7, 15, 18, 70, 56, true), DateException);
        CHECK_THROW(date1 < date3, DateException);
        CHECK_THROW(date1 == date3, DateException);
        CHECK_THROW(date1 += date2, DateException);
        CHECK_THROW(date1 = date3, DateException);
    }


}
