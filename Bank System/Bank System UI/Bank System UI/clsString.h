#pragma once
#include <iostream>
#include<string>
#include<vector>
using namespace std;


class clsString
{
private:
	string _Value;

public:
	clsString()
	{
		_Value = "";

	}

	clsString(string Value)
	{
		_Value = Value;
	}


	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	static short CountWords(string S1)
	{
		short Counter = 0;
		string delime = " ";
		short pos = 0;
		string Sword;
		while ((pos = S1.find(delime)) != std::string::npos)
		{
			Sword = S1.substr(0, pos);
			if (Sword != "")
				Counter++;

			S1.erase(0, pos + delime.length());

		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter++;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}



	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstChar = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstChar && S1[i] != ' ')
			{
				S1[i] = toupper(S1[i]);
			}

			IsFirstChar = S1[i] == ' ' ? true : false;

		}

		return S1;

	}
	void  UpperFirstLetterOfEachWord()
	{
		_Value= UpperFirstLetterOfEachWord(_Value);
	}


	static string LowerFirstCharInEachWord(string S1)
	{
		bool IsFirstChar = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsFirstChar && S1[i] != ' ')
			{
				S1[i] = tolower(S1[i]);
			}

			IsFirstChar = S1[i] == ' ' ? true : false;
		}


		return S1;

	}

	void LowerFirstCharInEachWord()
	{
		_Value = LowerFirstCharInEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{

			S1[i] = toupper(S1[i]);

		}


		return S1;

	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{

			S1[i] = tolower(S1[i]);

		}


		return S1;

	}

	void LowerAllString()
	{

		_Value = LowerAllString(_Value);

	}




	static char InvertLetterCase(char C1)
	{

		return isupper(C1) ? tolower(C1) : toupper(C1);

	}



	static string InvertAllLettersCase(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{

			S1[i] = InvertLetterCase(S1[i]);

		}


		return S1;

	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{


		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}

	static short CountCapitalLetters(string S1)
	{
		short CapitalLetters = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				CapitalLetters++;
			}

		}

		return CapitalLetters;

	};

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	};


	static short CountSmallLetters(string S1)
	{
		short SmallLetters = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				SmallLetters++;
			}

		}

		return SmallLetters;

	};

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);

	};

	static short CountSpecificLetter(string S1, char Ch1, bool MatchCase = true)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Ch1)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Ch1))
					Counter++;
			}


		}
		return Counter;
	}


	short CountSpecificLetter(char Ch1,bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Ch1,MatchCase);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');

	}

	


	static short CountVowel(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}

		return Counter;
	}


	short CountVowel()
	{
		return CountVowel(_Value);
	}

	

	static vector<string> Split(string S1, string delime)
	{
		vector<string>vWords;
		short pos = 0;
		string Sword;
		while ((pos = S1.find(delime)) != std::string::npos)
		{
			Sword = S1.substr(0, pos);
			if (Sword != "")
			{
				vWords.push_back(Sword);
			}

			S1.erase(0, pos + delime.length());

		}
		if (S1 != "")
		{
			vWords.push_back(S1);
		}

		return vWords;

	}

	vector<string> Split(string delime = " ")
	{
		return Split(_Value, delime);
	}

	static string TrimLeft(string S1)
	{

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value= TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}

		}
		return "";

	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string>vString, string Delime)
	{
		string S1;

		for (string& i : vString)
		{
			S1 += i + Delime;
		}

		return S1.substr(0, S1.length() - Delime.length());
	}



	static string RevrseWordsInString(string S1)
	{
		string S2;

		vector<string>vString = Split(S1, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S2 += *iter + " ";

		}

		return S2.substr(0, S2.length() - 1);

	}

	void RevrseWords()
	{
		_Value = RevrseWordsInString(_Value);
	}

	static string ReblaceWordUsingBuiltInFunction(string S1, string StringToReblace, string sReblaceTo)
	{
		short pos = S1.find(StringToReblace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReblace.length(), sReblaceTo);

			pos = S1.find(StringToReblace);

		}

		return S1;

	}

	void ReblaceWordUsingBuiltInFunction(string StringToReblace, string sReblaceTo)
	{
		_Value= ReblaceWordUsingBuiltInFunction(_Value, StringToReblace, sReblaceTo);
	}


	static string ReblaceWordUsingSpilt(string S1, string StringToReblace, string sReblaceTo, bool Matchcase = true)
	{
		vector<string>vString = Split(S1, " ");
		for (string& s : vString)
		{
			if (Matchcase)
			{
				if (s == StringToReblace)
					s = sReblaceTo;
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReblace))
				{
					s = sReblaceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}


	void ReblaceWordUsingSpilt(string StringToReblace, string sReblaceTo, bool Matchcase = true)
	{
		_Value = ReblaceWordUsingSpilt(_Value,StringToReblace, sReblaceTo, Matchcase);
	}

	static string RemovePauncrations(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}

		}

		return S2;
	}

	string RemovePauncrations()
	{

		_Value= RemovePauncrations(_Value);
	}



};

