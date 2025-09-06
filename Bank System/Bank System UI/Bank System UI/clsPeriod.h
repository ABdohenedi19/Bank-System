#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }


    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    static bool IsDateInPeriod(clsDate Date, clsPeriod Period)
    {
        return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before ||
            clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);

        /*return IsDate1AfterDate2(Date, Period.DateFrom) || IsDate1BeforeDate2(Date, Period.DateTo);*/

    }


     bool IsDateInthisPeriod(clsDate Date)
    {
        return !(clsDate::CompareDates(Date, this->StartDate) == clsDate::enDateCompare::Before ||
            clsDate::CompareDates(Date, this->EndDate) == clsDate::enDateCompare::After);

        /*return IsDate1AfterDate2(Date, Period.DateFrom) || IsDate1BeforeDate2(Date, Period.DateTo);*/

    }


    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();


        cout << "Period End: ";
        EndDate.Print();


    }

};

