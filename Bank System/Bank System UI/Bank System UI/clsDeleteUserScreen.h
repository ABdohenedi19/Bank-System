#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include <iomanip>
using namespace std;

class clsDeleteUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissons;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t  Delete User Screen.");

        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User ? y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Succussfully :-)";
                _PrintUser(User);
            }

            else
            {
                cout << "\nErorr User was not Delete!!";
            }
        }
        else
        {
            cout << "\nOperation was Canselled.\n";
        }

    }
};

