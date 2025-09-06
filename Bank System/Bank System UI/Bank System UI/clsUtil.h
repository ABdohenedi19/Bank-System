#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
 
using namespace std;

class clsUtil
{
public:

	enum enCharType { SmallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4,SpecialCharacter=5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	// Random Methods

	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
		}
		case enCharType::MixChars:
		{
			return GetRandomCharacter((enCharType)RandomNumber(1,3));
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
		}

		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	// Swap Methods

	static void Swap(int& x, int& y)
	{
		int Temp = 0;
		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(double& x, double& y)
	{
		double Temp = 0;
		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(bool& x, bool& y)
	{
		bool Temp;
		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(char& x, char& y)
	{
		char Temp;
		Temp = x;
		x = y;
		y = Temp;
	}


	static void Swap(string& x, string& y)
	{
		string Temp = "";
		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate.Day = Date1.Day;
		TempDate.Month = Date1.Month;
		TempDate.Year = Date1.Year;


		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;


		Date2.Day = TempDate.Day;
		Date2.Month = TempDate.Month;
		Date2.Year = TempDate.Year;
	}

	// Shuffle Array

	static void ShuffleArray(int arr[], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			Swap(arr[RandomNumber(1, Length) - 1], arr[RandomNumber(1, Length) - 1]);
		}
	}

	static void ShuffleArray(string arr[], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			Swap(arr[RandomNumber(1, Length) - 1], arr[RandomNumber(1, Length) - 1]);
		}
	}

	// Fill Array With Random

	static void FillArrayWithRandomNumbers(int arr[], int Length,int From,int To)
	{
		for (int i = 0; i < Length; i++)
			arr[i] = RandomNumber(From, To);
	}


	static void FillArrayWithRandomWords(string arr[], int Length,enCharType CharType ,int WordLength)
	{
		for (int i = 0; i < Length; i++)
			arr[i] = GenerateWord(CharType,WordLength);
	}


	static void FillArrayWithRandomKeys(string arr[], int Length, enCharType CharType)
	{
		for (int i = 0; i < Length; i++)
			arr[i] = GenerateKey(CharType);
	}

	static string Tabs(short NumberOfTaps)
	{
		string t = "";
		for (short i = 1; i <= NumberOfTaps; i++)
		{
			t += "\t";
			cout << t;
		}
		return t;				
	}

	static string EncryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}
	static string DecryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}
	static string NumberToText(long long int Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{

			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
			"Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return arr[Number];

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);

		}
		if (Number >= 100 && Number <= 199)
		{

			return "One  Hundred " + NumberToText(Number % 100);

		}
		if (Number >= 200 && Number <= 999)
		{

			return NumberToText(Number / 100) + " Hundreds" + " " + NumberToText(Number % 100);

		}

		if (Number >= 1000 && Number <= 1999)
		{

			return "One Thousand " + NumberToText(Number % 1000);

		}
		if (Number >= 2000 && Number <= 999999)
		{

			return NumberToText(Number / 1000) + " Thousands" + " " + NumberToText(Number % 1000);

		}
		if (Number >= 1000000 && Number <= 1999999)
		{

			return "One Million " + NumberToText(Number % 1000000);

		}
		if (Number >= 2000000 && Number <= 999999999)
		{

			return NumberToText(Number / 1000000) + " Millions" + " " + NumberToText(Number % 1000000);

		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{

			return "One Billion " + NumberToText(Number % 1000000000);
		}

		if (Number >= 2000000000 && Number <= 999999999999)
		{

			return NumberToText(Number / 1000000000) + " Billions" + " " + NumberToText(Number % 1000000000);

		}
	}

};

