#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsShowWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
#include <iomanip>
using namespace std;
class clsTransactionsScreen:protected clsScreen
{
private:

    enum enTransactionsMenueOptions
    {
        eDeposit=1,eWithdraw=2
        ,eTotalBalance=3,eTransfer=4,eTransferLog=5,eMainMenue=6
    };
    static short _ReadTransactionsMenueOption()
    {
        short Option;
        cout << setw(37) << left << "" << "Choose What do you want to do? [1:6] ? ";
        Option = clsInputValidate::ReadShortNumberBetween(1, 6);
        return Option;
    }

    static void _GoBackToTransactionsScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to Go back To Transactions Menue...\n";
        system("pause>0");
        ShowTransactionsMenueScreen();
    }

    static void _ShowDepositScreen()
    {
       // cout << "\n Deposit Screen will be here ......\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here ......\n";
        clsShowWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Total Balances Screen will be here ......\n";

        clsTotalBalancesScreen::ShowTotalBalances();
      
    }

    static void _ShowTransferScreen()
    {
        //cout << "\n Transfer Screen will be here ......\n";
        clsTransferScreen::ShowTransferScreen();

    }

    static void _ShowTransferLogScreen()
    {
        //cout << "\n Transfer Log Screen will be here ......\n";

        clsTransferLogScreen::ShowTransfersLogScreen();
    }

    static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions TransactionsMenueOption)
    {

        switch (TransactionsMenueOption)
        {
        case clsTransactionsScreen::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsScreen();
            break;
        case clsTransactionsScreen::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsScreen();
            break;
        case clsTransactionsScreen::eTotalBalance:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsScreen();
            break;
        case clsTransactionsScreen::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsScreen();
        case clsTransactionsScreen::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsScreen();
        case clsTransactionsScreen::eMainMenue:
          // Do Nothing   
            break;
        }



    }


public:
	static void ShowTransactionsMenueScreen()
	{
        if (!CheakAccessRight(clsUser::enPermissions::pTransaction))
        {
            return;// this will go out Funtion
        }


        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transefer.\n";
        cout << setw(37) << left << "" << "\t[5] Transefer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "=====================================================\n";

        _PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionsMenueOption());

	}




};

