#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"
using namespace std;


class clsUpdateRateScreen:protected clsScreen
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

	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("\t Update Rate Screen");

		string CurrencyCode = _ReadCurrencyCode();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrenyCard(Currency);

		float Rate;
		char Answer = 'n';
		char UpdateMord = 'n';

		cout << "\nPlese Enter New Rate : ";
		Rate = clsInputValidate::ReadFloatNumber();

		cout << "\nAre you sure you want to do this update? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Currency.UpdateRate(Rate);
			cout << "\nUpdate Done Successfully :-)\n";

			_PrintCurrenyCard(Currency);
		}
		else
		{
			cout << "\nUpdate was Cnselled:-(";
			return;
		}

		
		cout << "\ndo you want to do many updates? ";
		cin >> UpdateMord;
		if (UpdateMord == 'y' || UpdateMord == 'Y')
		{
			system("cls");
			ShowUpdateRateScreen();
		}
	}




};

