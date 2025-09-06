#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsScreen.h"
using namespace std;
class clsListCurrenceiesScreen:protected clsScreen
{
private:
	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << setw(10) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(35) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();

	}

public:

	static void ShowListCurrenceiesScreen()
	{
		vector<clsCurrency>vCurrenceies = clsCurrency::GetCurrenciesList();

		string Titel = "\t Currenceies List Screen";
		string SubTitel = "\t   (" + to_string(vCurrenceies.size()) + ") Currencey(s).";

		_DrawScreenHeader(Titel, SubTitel);

		cout << setw(10) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << setw(8) << left << "Code";
		cout << "| " << setw(35) << left << "Name";
		cout << "| " << setw(10) << left << "Rate(1$)";
		cout << endl;
		if (vCurrenceies.size() == 0)
		{
			cout << "\nNo Currences Avaliable In System.";
		}

		for (clsCurrency& C : vCurrenceies)
		{
			_PrintCurrencyRecord(C);
			cout << endl;
		}


	}

};

