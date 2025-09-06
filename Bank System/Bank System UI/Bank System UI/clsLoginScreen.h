#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsMainScreen.h"
#include"Global.h"

using namespace std;

class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		short LoginFailedCount = 0;
		string UserName, Password;
		do
		{
			if (LoginFaild)
			{
				cout << "\nInvalied UserName/Password!!\n";
				LoginFailedCount++;
				cout << "You have " << (3 - LoginFailedCount) << " Triels to Login.\n\n";
			}

			if (LoginFailedCount == 3)
			{
				cout << "\n\nyou are locked after 3 failed triels\n\n";
				return false;
			}


			cout << "Enter UserName? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RgisterLogin();
		clsMainScreen::ShowMainMenue();
		
		return true;
	}



public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");

		return _Login();
	}



};

