#include <iostream>
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsBankClient.h"
using namespace std;

void ReadClientInfo(clsBankClient & Client)
{
    cout << "\nEnter First Name : ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter Last Name : ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email : ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone : ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode : ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance : ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();


}

void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(20) << left << Client.Email;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowClientList()
{
    vector<clsBankClient>vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient & Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}
void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(25) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowTotalBalances()
{
    vector <clsBankClient>vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(25) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;

            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
    cout << "\n\t\t\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ")\n";

}
void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExit(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    //Client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";


    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObj:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    }
}
void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nEnter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExit(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {

    case clsBankClient::svFaildEmptyObj:
        cout << "\nError account was not save, because it's Empty";
        break;

    case clsBankClient::svSucceeded:
        cout << "\nAccount Addeded Successfully :-)\n";
        NewClient.Print();
        break;

    case clsBankClient::svFaildAccountNumberExists:
        cout << "\nError account was not saved because account number is used!\n";
        break;
    }

}
void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExit(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\nAre you sure you want to delete this Client ? y/n? ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        if (Client.Delete())
        {
            cout << "\nClient Deleted Succussfully :-)";
            Client.Print();
        }

        else
        {
            cout << "\nErorr Client was not Delete!!";
        }
    }

}


int main()
{
   
    


    

    system("pause>0");

    return 0;

}


