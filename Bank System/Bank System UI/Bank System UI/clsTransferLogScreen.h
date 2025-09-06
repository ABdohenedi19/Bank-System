#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsTransferLogScreen:protected clsScreen
{
private:
    static void _PrintTransferRecordBalanceLine(clsBankClient::stTransferLog TransferRecord)
    {
        cout << setw(10) << left << "" << "| " << setw(25) << left << TransferRecord.Date;
        cout << "| " << setw(10) << left << TransferRecord.s_AccountNumber;
        cout << "| " << setw(10) << left << TransferRecord.d_AccountNumber;
        cout << "| " << setw(10) << left << TransferRecord.Amount;
        cout << "| " << setw(10) << left << TransferRecord.d_AccountBalance;
        cout << "| " << setw(10) << left << TransferRecord.s_AccountBalance;
        cout << "| " << setw(10) << left << TransferRecord.UserName;
    }


public:


    static void ShowTransfersLogScreen()
    {
        vector <clsBankClient::stTransferLog>vTransfers = clsBankClient::GetTransferList();

        string Titel = "\t Transfer Log Screen";
        string SubTitel = "\t   (" + to_string(vTransfers.size()) + ") Transfer(s).";

        _DrawScreenHeader(Titel, SubTitel);

        cout << setw(10) << left << "" << "\n\t___________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(10) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s_Acct";
        cout << "| " << left << setw(10) << "d_Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s_Balance";
        cout << "| " << left << setw(10) << "d_Balance";
        cout << "| " << left << setw(10) << "User Name";
        cout << setw(10) << left << "" << "\n\t___________________________________________________________";
        cout << "_________________________________________\n" << endl;

        

        if (vTransfers.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLog & Transfer : vTransfers)
            {

                _PrintTransferRecordBalanceLine(Transfer);

                cout << endl;
            }

        cout << setw(10) << left << "" << "\n\t___________________________________________________________";
        cout << "_________________________________________\n" << endl;


    }




};

