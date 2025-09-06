#pragma once
#include<iostream>
#include"clsListCurrenceiesScreen.h"
#include"clsFindCurrenceiesScreen.h"
#include"clsUpdateRateScreen.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsCurrencyExchangeScreen:protected clsScreen
{
private:

    enum enCurrnencyExchangeOptions
    {
        eListCurren = 1, eFindCurren = 2
        , eUpdateRate = 3, eCalculator = 4
        , eMainMenue = 5
    };

    static short _ReadCurrencyExchangeOptions()
    {
        cout << setw(37) << left << "" << "Choose What do you want to do? [1:5] ? ";
        short Option = clsInputValidate::ReadShortNumberBetween(1, 5);

        return Option;
    }

    static void _GoBackToCurrencyExchangeScreen()
    {

        cout << setw(37) << left << "" << "\n\tPress any key to Go back To Currency Exchange...\n";
        system("pause>0");

        ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrenciesScreen()
    {
         //cout << "\n  list Currences Screen will be here ....\n";
        clsListCurrenceiesScreen::ShowListCurrenceiesScreen();
    }

    static void _ShowFindCurrenciesScreen()
    {
        //cout << "\n  Find Currences Screen will be here ....\n";
        clsFindCurrenceiesScreen::ShowFindCurrenciesScreen();

    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\n Update Rate Screen will be here ....\n";
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCalculatorCurrencyScreen()
    {
       // cout << "\n Calculator Currency Screen will be here ....\n";

    }


    static void _PerformCurrencyExchangeOptions(enCurrnencyExchangeOptions Option)

    {
        switch (Option)
        {
        case clsCurrencyExchangeScreen::eListCurren:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case clsCurrencyExchangeScreen::eFindCurren:
            system("cls");
            _ShowFindCurrenciesScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case clsCurrencyExchangeScreen::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case clsCurrencyExchangeScreen::eCalculator:
            system("cls");
            _ShowCalculatorCurrencyScreen();
            _GoBackToCurrencyExchangeScreen();
            break;
        case clsCurrencyExchangeScreen::eMainMenue:
            // Do Nothing
            break;
        }
    }



public:
	static void ShowCurrencyExchangeScreen()
	{
        system("cls");
        _DrawScreenHeader("\t\tCurrency Exchange Screen");
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currencies.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "=====================================================\n";

        _PerformCurrencyExchangeOptions((enCurrnencyExchangeOptions)_ReadCurrencyExchangeOptions());

	}



};

