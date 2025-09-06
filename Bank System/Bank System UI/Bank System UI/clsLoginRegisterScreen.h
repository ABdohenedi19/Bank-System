#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include <iomanip>
using namespace std;
class clsLoginRegisterScreen:protected clsScreen
{
private:
    static void _PrintRegisterRecordLine(clsUser::stLoginRegister Register)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << Register.DateTime;
        cout << "| " << setw(15) << left << Register.UserName;
        cout << "| " << setw(10) << left << Register.Password;
        cout << "| " << setw(12) << left << Register.Permissions;

    }

public:

    static void ShowClientList()
    {

        if (!CheakAccessRight(clsUser::enPermissions::pLoginRegister))
        {
            return;// this will go out Funtion
        }


        vector<clsUser::stLoginRegister>vRegisters = clsUser::GetRegistersList();

        string Titel = "\t\Registers List Screen.";
        string SubTitel = "\t  (" + to_string(vRegisters.size()) + ") Register(s).";

        _DrawScreenHeader(Titel, SubTitel);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date Time";
        cout << "| " << left << setw(15) << "User Name";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRegisters.size() == 0)
            cout << "\t\t\t\tNo Registers Available In the System!";
        else

            for (clsUser::stLoginRegister & Register : vRegisters)
            {

                _PrintRegisterRecordLine(Register);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};

