#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsAddNewUsersScreen:protected clsScreen
{
private:
    static void _ReadClientInfo(clsUser & User)
    {
        cout << "\nEnter First Name : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password : ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions : ";
        User.Permissons = _ReadPermissons();


    }
	static short _ReadPermissons()
	{
		short P = 0;
		char Answer = 'n';

		cout << "\n Do you want to give full access to this User? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\ngive access to :";

		cout << "\n\n Show Client List? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pClientsList;
		}

		cout << "\n Show Add New Client Screen? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pAddClient;
		}


		cout << "\n Show Delete Client Screen? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\n Show Update Client Screen? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\n Show Find Client Screen? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pFindClient;
		}

		cout << "\n Transactions? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pTransaction;
		}

		cout << "\n Manage User ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pManageUsers;
		}

		cout << "\n Login Register ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			P += clsUser::enPermissions::pLoginRegister;
		}

		return P;
	}
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
    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("\t  Add New User Screen.");

        string UserName = "";

        cout << "\nPlese Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name["<<UserName<<"] Is Already Used, Choose another one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadClientInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {

        case clsUser::svFaildEmptyObj:
            cout << "\nError account was not save, because it's Empty";
            break;

        case clsUser::svSucceeded:
            cout << "\nAccount Addeded Successfully :-)\n";
	
            _PrintUser(NewUser);
            break;

        case clsUser::svFaildUserNameExists:
            cout << "\nError account was not saved because user name is used!\n";
            break;
        }

    }
};

