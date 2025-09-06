#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUsersScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include <iomanip>


using namespace std;
class clsManageUsersScreen:protected clsScreen
{
private:
    enum enManageUsersOptions 
    {
        elistUsers=1,eAddUser=2
        ,eDeleteUser=3,eUpdateUser=4
        ,eFindUser=5,eMainMenue

    };

    static short _ReadManageUsersOption()
    {
        cout << setw(37) << left << "" <<"  Choose what do you want to do? [1:6] ? ";
        short Option = clsInputValidate::ReadShortNumberBetween(1, 6);

        return Option;
    }

    static void _GoBackToManageUsersScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to Go back To Manage User Menue...\n";
        system("pause>0");

        ShowManageUsersScreen();
    }

    static void _ShowListUsersScreen()
    {
        //cout << "\n List Users screen will be here ....\n";
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
       //cout << "\n Add New User screen will be here ....\n";
        clsAddNewUsersScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "\n Delete User screen will be here ....\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
        
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\n Update User screen will be here ....\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
        //cout << "\n Find User screen will be here ....\n";
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersOption(enManageUsersOptions ManageUsersOption)
    {
        switch (ManageUsersOption)
        {
        case clsManageUsersScreen::elistUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eAddUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case clsManageUsersScreen::eMainMenue:
            // Do Nothing
            break;

        }
    }


public:
	static void ShowManageUsersScreen()
	{
        if (!CheakAccessRight(clsUser::enPermissions::pManageUsers))
        {
            return;// this will go out Funtion
        }

        system("cls");
        _DrawScreenHeader("\t\tManage Users Screen");
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t\t\tManage Users Menue\n";
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "=====================================================\n";

        _PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersOption());
	}



};

