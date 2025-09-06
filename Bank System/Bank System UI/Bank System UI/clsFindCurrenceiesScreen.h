#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"
using namespace std;
class clsFindCurrenceiesScreen:protected clsScreen
{
private:
	static string _ReadCurrencyCode()
	{
		string Code = "";
		cout << "Enter Curreny Code : ";
		Code = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurrncy Not Found ,Plese enter another one:";
			Code = clsInputValidate::ReadString();
		}
		return Code;
	}

	static void  _PrintCurrenyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Info:";

		cout << "\n___________________";
		cout << "\nCountry   : " << Currency.Country();
		cout << "\nCode      : " << Currency.CurrencyCode();
		cout << "\nName      : " << Currency.CurrencyName();
		cout << "\nRate(1$)  : " << Currency.Rate();
		cout << "\n___________________\n";
	}






public:

	static void ShowFindCurrenciesScreen()
	{
		_DrawScreenHeader("\t Find Curreny Screen");

		string CurrencyCode = _ReadCurrencyCode();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		cout << "\nCurrency Found:-)\n";

		_PrintCurrenyCard(Currency);


	}



};

