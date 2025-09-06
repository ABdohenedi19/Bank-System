#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:
    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(25) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }


public:


    static void ShowTotalBalances()
    {
        vector <clsBankClient>vClients = clsBankClient::GetClientsList();

        string Titel = "\t Total Balances Screen";
        string SubTitel = "\t   (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Titel,SubTitel);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_____________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(25) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_____________________________\n" << endl;

        double TotalBalances =clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordBalanceLine(Client);

                cout << endl;
            }

        cout <<setw(25)<<left<<""<< "\n\t\t_______________________________________________________";
        cout << "_____________________________\n" << endl;
        cout <<   "\t\t\t\t\t   Total Balances = " << TotalBalances;
        cout <<  "\n\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ")\n";

    }
};

