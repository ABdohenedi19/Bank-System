#pragma once
#include<iostream>
#include<string>
using namespace std;
class InterfaceCommunication
{
public:
	virtual void SendEmail(string Titel, string Body) = 0;
	virtual void SendFax(string Titel, string Body) = 0;
	virtual void SendSMS(string Titel, string Body) = 0;
};

