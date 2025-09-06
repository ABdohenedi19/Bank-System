#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;


class clsBankClient:public clsPerson
{
private:

	enum enClientMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};

	enClientMode _Mode;

	struct stTransferLog;


	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vClientDate;
		vClientDate = clsString::Split(Line,Seperator);

		return clsBankClient(enClientMode::UpdateMode, vClientDate[0], vClientDate[1], vClientDate[2]
			, vClientDate[3], vClientDate[4], vClientDate[5], stod(vClientDate[6]));

	}

	static clsBankClient::stTransferLog _ConvertLineToTransferRecord(string Line, string Seperator = "#//#")
	{
		clsBankClient::stTransferLog Record;
		vector<string>vTransfer = clsString::Split(Line, Seperator);

		Record.Date = vTransfer[0];
		Record.s_AccountNumber = vTransfer[1];
		Record.d_AccountNumber = vTransfer[2];
		Record.Amount = stod(vTransfer[3]);
		Record.s_AccountBalance = stod(vTransfer[4]);
		Record.d_AccountBalance = stod(vTransfer[5]);
		Record.UserName = vTransfer[6];

		return Record;
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string ClientLine = "";

		ClientLine += Client.FirstName + Seperator;
		ClientLine += Client.LastName + Seperator;
		ClientLine += Client.Email + Seperator;
		ClientLine += Client.Phone + Seperator;
		ClientLine += Client.AccountNumber() + Seperator;
		ClientLine += Client.PinCode + Seperator;
		ClientLine += to_string(Client.AccountBalance);

		return ClientLine;

	}

	static vector<clsBankClient::stTransferLog>_LoadTransferDataFromFile()
	{
		vector<clsBankClient::stTransferLog> vTransfer;

		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			clsBankClient::stTransferLog TransferLog;

			while (getline(MyFile, Line))
			{
				TransferLog = _ConvertLineToTransferRecord(Line);
				vTransfer.push_back(TransferLog);
			}
		

			MyFile.close();
		}

		return vTransfer;
	}


	static vector<clsBankClient>_LoadClientDataFromFile()
	{
		vector<clsBankClient>vClients;
		fstream MyFile;
		MyFile.open("Clients (1).txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile,Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);

			}

			MyFile.close();
		}

		return vClients;

	}

	void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients (1).txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;
			for (clsBankClient & C : vClients)
			{
				if (C._MarkForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}


	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;

		MyFile.open("Clients (1).txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}


	}

	string _PrepareTransferRecord(clsBankClient DestinationClient,double Amount,string UserName,string sparator = "#//#")
	{
		string RecordLine = "";

		RecordLine += clsDate::GetSystemDateString() + sparator;
		RecordLine += this->AccountNumber()+sparator;
		RecordLine += DestinationClient.AccountNumber() + sparator;
		RecordLine += to_string(Amount) + sparator;
		RecordLine += to_string(AccountBalance) + sparator;
		RecordLine += to_string(DestinationClient.AccountBalance) + sparator;
		RecordLine += UserName;

		return RecordLine;


	}

	void _RegisterTransferLog(clsBankClient DestinationClient, double Amount,string UserName)
	{
		string DataLine = _PrepareTransferRecord(DestinationClient, Amount,UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile<<DataLine << endl;


			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient>_vClients;

		_vClients = _LoadClientDataFromFile();

		for (clsBankClient & C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}




	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enClientMode::EmptyMode, "", "", "", "", "", "", 0);

	}



public:
	clsBankClient(enClientMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber,string PinCode ,float AccountBalance) :clsPerson
		(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		
	}

	struct stTransferLog
	{
		string Date;
		string s_AccountNumber;
		string d_AccountNumber;
		double Amount;
		double s_AccountBalance;
		double d_AccountBalance;
		string UserName;
	};


	bool IsEmpty()
	{
		return (_Mode == enClientMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	// No UI Related Inside Object!!!
	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}*/

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;

		MyFile.open("Clients (1).txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream MyFile;

		MyFile.open("Clients (1).txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();

		}

		return _GetEmptyClientObject();

	}

	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients;
		vClients = _LoadClientDataFromFile();
		double TotalBalances = 0;
		for (clsBankClient& C : vClients)
		{

			TotalBalances += C.AccountBalance;

		}

		return TotalBalances;
	}


	enum enSaveResults{svFaildEmptyObj=0, svSucceeded = 1, svFaildAccountNumberExists = 2};


	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else 
		{
			/*_AccountBalance -= Amount;
			Save();*/

			/*Or*/ Deposit(-Amount);
			return true;
		}

	}

	 bool Transfer(double Amount,clsBankClient & DestinationClient,string UserName)
	{
		if (Amount>AccountBalance)
		{
			return false;

		}
		
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(DestinationClient, Amount,UserName);
		return true;
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResults::svFaildEmptyObj;

		case clsBankClient::UpdateMode:
			 _Update();
			return enSaveResults::svSucceeded;
		
		case clsBankClient::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}

			_AddNew();

			_Mode = enClientMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}


	}


	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());
	}

	bool Delete()
	{
		vector<clsBankClient>vClients = _LoadClientDataFromFile();

		for (clsBankClient & C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;
			}


		}
	
		_SaveClientsDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;

	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	static vector<clsBankClient::stTransferLog> GetTransferList()
	{
		return _LoadTransferDataFromFile();
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{

		return clsBankClient(enClientMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

};

