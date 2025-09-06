#pragma once
#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>
class clsCurrency
{
private:

	enum enMode{EmptyMode=0,UpdateMode=1};

	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Sparator = "#//#")
	{
		vector<string>vCurrencies;

		vCurrencies = clsString::Split(Line, Sparator);

		return clsCurrency(enMode::UpdateMode, vCurrencies[0], vCurrencies[1],
			vCurrencies[2], stof(vCurrencies[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Sparator = "#//#")
	{
		string DataLine = "";
	
		DataLine += Currency.Country() + Sparator;
		DataLine += Currency.CurrencyCode() + Sparator;
		DataLine += Currency.CurrencyName() + Sparator;
		DataLine += to_string(Currency.Rate());

		return DataLine;
	}

	static vector<clsCurrency>_LoadCurrencyDataFromFile()
	{
		vector< clsCurrency>vCurrencies;
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile,Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrencies;
	}


	static void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;

			for (clsCurrency& C : vCurrencies)
			{
				Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line << endl;

			}

			MyFile.close();
		}

	}


	void _Update()
	{

		vector<clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:
	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencyDataFromFile();

	}


	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}


	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}


};

