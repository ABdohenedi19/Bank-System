#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include"clsDate.h"
#include"clsUtil.h"
#include <fstream>

using namespace std;

class clsUser:public clsPerson
{
private:

	enum enUserMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };


	

	enUserMode _Mode;

	string _UserName;
	string _Password;
	short _Permissions;
	bool _MarkForDelete = false;

	struct stLoginRegister;


	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string>vUsersDate;
		vUsersDate = clsString::Split(Line, Seperator);

		return clsUser(enUserMode::UpdateMode, vUsersDate[0], vUsersDate[1], vUsersDate[2]
			, vUsersDate[3], vUsersDate[4], clsUtil::DecryptText(vUsersDate[5]), stod(vUsersDate[6]));

	}
	static clsUser::stLoginRegister _ConvertLineToUserRegisterObject(string Line, string Seperator = "#//#")
	{
		clsUser::stLoginRegister Register;
	
		vector<string>vRegistersDate;
		vRegistersDate = clsString::Split(Line, Seperator);

		Register.DateTime = vRegistersDate[0];
		Register.UserName = vRegistersDate[1];
		Register.Password = clsUtil::DecryptText(vRegistersDate[2]);
		Register.Permissions = stoi(vRegistersDate[3]);

		return Register;

	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string UserLine = "";

		UserLine += User.FirstName + Seperator;
		UserLine += User.LastName + Seperator;
		UserLine += User.Email + Seperator;
		UserLine += User.Phone + Seperator;
		UserLine += User.UserName + Seperator;
		UserLine += clsUtil::EncryptText(User.Password) + Seperator;
		UserLine += to_string(User._Permissions);

		return UserLine;

	}

	static vector<clsUser>_LoadUserDataFromFile()
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);

			}

			MyFile.close();
		}

		return vUsers;

	}

	static vector<clsUser::stLoginRegister>_LoadUserRegisterDataFromFile()
	{
		vector<clsUser::stLoginRegister>vRegisters;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser::stLoginRegister UsersRegister = _ConvertLineToUserRegisterObject(Line);
				vRegisters.push_back(UsersRegister);

			}

			MyFile.close();
		}

		return vRegisters;

	}

	void _SaveUsersDataToFile(vector<clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;
			for (clsUser& U : vUsers)
			{
				if (U._MarkForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}


	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}


	}

	string _PrepareLogInRegister(string sparator="#//#")
	{
		string RecordLine="";

		RecordLine += clsDate::GetSystemDateString() + sparator;
		RecordLine += UserName + sparator;
		RecordLine += Password+sparator;
		RecordLine += to_string(Permissons);

		return RecordLine;


	}

	void _Update()
	{
		vector<clsUser>_vUsers;

		_vUsers = _LoadUserDataFromFile();

		for (clsUser & U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);
	}




	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enUserMode::EmptyMode, "", "", "", "", "", "", 0);

	}






public:
	
	clsUser(enUserMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, short Permissons) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissons;
	}

	enum enPermissions
	{
		pAll = -1, pClientsList = 1, pAddClient = 2, pDeleteClient = 4
		, pUpdateClient = 8, pFindClient = 16, pTransaction = 32
		, pManageUsers = 64,pLoginRegister=128
	};

	struct stLoginRegister
	{
		string DateTime;
		string UserName;
		string Password;
		short Permissions;

	};
	bool IsEmpty()
	{
		return (_Mode == enUserMode::EmptyMode);
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get=GetUserName, put=SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;


	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}

	short GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissons;

	enum enSaveResults { svFaildEmptyObj = 0, svSucceeded = 1, svFaildUserNameExists = 2 };


	



	static clsUser Find(string UserName)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName,string Password)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);

		return (!User.IsEmpty());
	}


	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUser::EmptyMode:
			return enSaveResults::svFaildEmptyObj;

		case clsUser::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

		case clsUser::AddNewMode:
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserNameExists;
			}

			_AddNew();

			_Mode = enUserMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}


	}

	bool Delete()
	{
		vector<clsUser>vUsers = _LoadUserDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkForDelete = true;
				break;
			}


		}

		_SaveUsersDataToFile(vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	static vector<clsUser::stLoginRegister> GetRegistersList()
	{
		return _LoadUserRegisterDataFromFile();
	}

	static clsUser GetAddNewUserObject(string UserName)
	{

		return clsUser(enUserMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}


	bool CheakAccessPermissons(enPermissions Permissions)
	{
		if (this->Permissons == enPermissions::pAll)
			return true;

		if ((Permissions & this->Permissons) == Permissions)
			return true;
		else
			return false;


	}

	void RgisterLogin()
	{
		string DataLine=_PrepareLogInRegister();

		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;

			MyFile.close();
		}


	}



};

