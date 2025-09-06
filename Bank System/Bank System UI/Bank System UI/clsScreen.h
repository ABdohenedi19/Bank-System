#pragma once

#include <iostream>
#include"clsUser.h"
#include"clsDate.h"
#include"Global.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Titel, string SubTitel = "")
	{

		cout << "\t\t\t\t\t_____________________________________________";
		cout << "\n\n\t\t\t\t\t  " << Titel;
		if (SubTitel != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitel;
		}
		cout << "\n\t\t\t\t\t_____________________________________________\n\n";

		

		cout << "\t\t\t\t\tUser : " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate())<<"\n\n";

	}

	static bool CheakAccessRight(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheakAccessPermissons(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}



	}


};

