#pragma once

#include <iostream>
#include"clsDate.h"
#include"clsUtil.h"
#include"clsPeriod.h"
using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return Number >= From && Number <= To;
	}

	

	static bool IsDateBetween(clsDate Date, clsDate StartDate, clsDate EndDate)
	{
		if (clsDate::IsDate1BeforeDate2(EndDate, StartDate))
		{
			clsUtil::Swap(StartDate, EndDate);
		}

		return ((clsDate::CompareDates(Date, StartDate) == clsDate::After 
			||clsDate::CompareDates(Date, StartDate) == clsDate::Equal) &&
			(clsDate::CompareDates(Date, EndDate) == clsDate::Before)||
			clsDate::CompareDates(Date, EndDate) == clsDate::Equal);
			
	}

	static bool IsDateInPeriod(clsDate Date,clsPeriod Period)
	{
		return clsPeriod::IsDateInPeriod(Date, Period);
	}

	static int ReadIntNumber(string ErorrMessage = "Invalied int Number,Plese Enter a valied One:\n")
	{
		int Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErorrMessage;
			cin >> Number;
		}

		return Number;
	}
	static float ReadFloatNumber(string ErorrMessage = "Invalied float Number,Plese Enter a valied One:\n")
	{
		float Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErorrMessage;
			cin >> Number;
		}

		return Number;
	}
	static double ReadDoubleNumber(string ErorrMessage="Invalied double Number,Plese Enter a valied One:\n")
	{
		double Number;
		cin >> Number;
		while (!(cin >> Number)) // Or cin.fail() 
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErorrMessage << endl;
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To,
		string ErorrMessage = "Number is not within range,Plese enter another one:")
	{
		int Number = ReadIntNumber();

		while (Number<From || Number>To)
		{
			cout << ErorrMessage;
			cin >> Number;
		}

		return Number;


	}

	static double ReadDoubleNumberBetween(double From, double To,
		string ErorrMessage="Number is not within range,Plese enter another one:")
	{
		double Number=ReadDoubleNumber();
		while (Number<From || Number>To)
		{
			cout << ErorrMessage;
			cin >> Number;
		}

		return Number;
	}

	static string ReadString()
	{
		string S1;
		getline(cin >> ws, S1);

		return S1;
	}



	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}


};

