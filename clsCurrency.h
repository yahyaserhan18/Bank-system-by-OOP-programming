#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsString.h";

using namespace std;



class clsCurrency
{
private:
	enum enMode { emptyMod=1 , updateMod =2};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Separator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::splitStringToVector(Line, Separator);

		return clsCurrency(enMode::updateMod, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stod(vCurrencyData[3]));

	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.getCountry() + Seperator;
		stCurrencyRecord += Currency.getCurrencyCode() + Seperator;
		stCurrencyRecord += Currency.getCurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.getRate());

		return stCurrencyRecord;

	}

	static  vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{

		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencies.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencies;

	}


	static void _SaveCurrencyDataToFile(vector <clsCurrency>& vCurrencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency& C : vCurrencies)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;



			}

			MyFile.close();

		}

	}

	void _Update() {
		vector <clsCurrency> _vCurrencies;
		_vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : _vCurrencies)
		{
			if (C.getCurrencyCode() == this->getCurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::emptyMod, "", "", "", 0);
	}

public:
	clsCurrency(enMode mode , string country , string currencyCode , string currencyName,float rate) {
		 _Mode=mode;
		 _Country=country;
		 _CurrencyCode= currencyCode;
		 _CurrencyName= currencyName;
		 _Rate= rate;
	}
	string getCountry() {
		return _Country;
	}
	string getCurrencyCode() {
		return _CurrencyCode;
	}
	string getCurrencyName() {
		return _CurrencyName;
	}

	float getRate() {
		return _Rate;
	}
	void UpdateRate(float newRate) {
		_Rate = newRate;
		_Update();
	}
	

	bool isEmpty() {
		return this->_Mode == enMode::emptyMod;
	}

	static clsCurrency FindByCode(string currencyCode) {
		currencyCode = clsString::UpperString(currencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperString(Currency.getCurrencyCode()) == currencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}

	static   clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperString(Currency.getCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}



	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.isEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	void print() {
		cout << "\nCurrency Card : \n";
		cout << "___________________________________\n";

		cout << "Country  : " << this->getCountry() << endl;
		cout << "Code     : " << this->getCurrencyCode() << endl;
		cout << "Name     : " << this->getCurrencyName() << endl;
		cout << "Rate(1$) : " << this->getRate() << endl;
		cout << "___________________________________\n\n";

	}

	float convertFromDollarsToLocalCurrency(float amount) {
		return amount * this->getRate();
	}
	float convertToDollars(float amount) {
		return amount / this->getRate();
	}

	static float ExchangeAmountToOtherCurrency(clsCurrency cur1 , clsCurrency cur2 , float amount) {
		float dollars = cur1.convertToDollars(amount);
		if (cur2.getRate() == 1)
			return dollars;

		return cur2.convertFromDollarsToLocalCurrency(dollars);


	}
};

