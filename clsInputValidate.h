#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "clsDate.h";
#include "clsUtil.h";
using namespace std;

class clsInputValidate
{
	
public:


	static bool IsNumberBetween(int number, int from, int to) {
		return (number > from && number < to);
	}
	static bool IsNumberBetween(double number, double from, double to) {
		return (number > from && number < to);
	}
	static bool IsDateBetween(clsDate date,clsDate from ,clsDate to) {
		if (clsDate::IsDate1AfterDate2(from,to))
			clsUtil::Swap(from, to);

		return ((clsDate::IsDate1AfterDate2(date, from)|| clsDate::IsDate1EqualDate2(date, from) ) && (clsDate::IsDate1BeforeDate2(date, to) || clsDate::IsDate1EqualDate2(date, to)));
	}
	static int readIntNumber(string message,string spaces="") {
		int n = 0;
		cout << message;cin >> n;

		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << spaces+"Error : Invalid number!\n" << message;cin >> n;
		}

		return n;
	}
	static int readPositiveNumber(string message) {
		int n = 0;
		cout << message;cin >> n;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Error : Invalid number! , " << message;cin >> n;
		}

		while (n < 0) {
			cout << "Error : Out Range!  " << message;cin >> n;
		}
		return n;
	}
	static float readFloatPositiveNumber(string message) {
		float n = 0;
		cout << message;cin >> n;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Error : Invalid number! , " << message;cin >> n;
		}

		while (n < 0) {
			cout << "Error : Out Range!  " << message;cin >> n;
		}
		return n;
	}
	static double readDoubleNumber(string message) {
		double n = 0;
		cout << message;cin >> n;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Error : Invalid number! , " << message;cin >> n;
		}
		return n;
	}
	static int readNumberInRange(int from, int to, string message,string spaces="") {
		int n = readIntNumber(message,spaces);
		
		while (n<from || n>to) {
			cout <<spaces+ "Error : Out Range!\n";n = readIntNumber(message,spaces);
		}
		return n;
	}

	static string readString(string message)
	{
		string s;
		cout << message;getline(cin >> ws, s);
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Error : Invalid value! , " << message;getline(cin >> ws, s);
		}
		return s;
	}

	static char readChar(string message) {
		char c = ' ';
		cout << message; cin >> c;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Error : Invalid value! , " << message;cin >> c;
		}
		return c;
	}

	static bool IsValidDate(clsDate date) {
		return clsDate::IsValidDate(date);
	}
};

