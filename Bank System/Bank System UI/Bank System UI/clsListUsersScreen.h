#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include <iomanip>
using namespace std;

class clsListUsersScreen : protected clsScreen
{
private:
    static void _PrintUsertRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(25) << left << User.Email;
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(12) << left << User.Permissons;

    }

public:

    static void ShowUsersList()
    {
        vector<clsUser>vUsers = clsUser::GetUsersList();

        string Titel = "\t\tUsers List Screen.";
        string SubTitel = "\t\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Titel, SubTitel);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(25) << "Email";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Permissons";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser& User : vUsers)
            {

                _PrintUsertRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

