#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientsScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include"Global.h"
#include <iomanip>


using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eLoginRegister=8,eCurrencyExchange = 9 ,eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose What do you want to do? [1:10] ? ";
        short Option = clsInputValidate::ReadShortNumberBetween(1, 10);

        return Option;
    }

    static void _GoBackToMainMenueScreen()
    {

        cout << setw(37) << left << "" << "\n\tPress any key to Go back To Main Menue...\n";
        system("pause>0");

        ShowMainMenue();
    }
  
    static void _ShowAllClientsScreen()
    {
       // cout << "\n Client list screen will be here ....\n";
        clsClientsListScreen::ShowClientList();
    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\n Add new clients screen will be here ....\n";
        clsAddNewClientsScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\n Delete client screen will be here ....\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\n Update client screen will be here ....\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }
    static void _ShowFindClientScreen()
    {
        //cout << "\n Find client screen will be here ....\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsScreen()
    {
        //cout << "\n Transactions screen will be here ....\n";
        clsTransactionsScreen::ShowTransactionsMenueScreen();
    }

    static void _ShowManageUsersScreen()
    {
       // cout << "\n Manage Users screen will be here ....\n";
        clsManageUsersScreen::ShowManageUsersScreen();

    }

    static void _ShowLoginRegisterList()
    {
        // cout << "\n Login Register List screen will be here ....\n";
        clsLoginRegisterScreen::ShowClientList();

    }

    static void _ShowCurrencyExchangeMainScreen()
    {
        // cout << "\n Currency Exchange screen will be here ....\n";
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }


   /* static void _ShowEndScreen()
    {
        cout << "\n End screen will be here ....\n";

    }*/

    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");

        //this will back to main Function

    }

    static void _PerformMainMenueOptions(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eManageUsers:
            system("cls");
            _ShowManageUsersScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eLoginRegister:
            system("cls");
            _ShowLoginRegisterList();
            _GoBackToMainMenueScreen();
        case clsMainScreen::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMainScreen();
            _GoBackToMainMenueScreen();

        case clsMainScreen::eExit:
            system("cls");
            _Logout();

            break;
        }

    }

public:
    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Clients Screen.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Clients.\n";  
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";    
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";      
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";     
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";    
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "=====================================================\n";

        _PerformMainMenueOptions((enMainMenueOptions)_ReadMainMenueOption());

    }

    

};

