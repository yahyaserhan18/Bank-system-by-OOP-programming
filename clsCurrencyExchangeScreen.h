#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUtil.h";
#include "clsInputValidate.h";
#include "clsBankUser.h";
#include "clsCurrenciesList.h";
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyScreen.h";
#include "clsCurrencyCalculatorScreen.h";
using namespace std;



class clsCurrencyExchangeScreen:clsScreen
{
private:
	enum enOptions{listCurrencies=1,findCurrency,updateRate,currencyCalculator,mainMenu};
	static void _ShowMenu() {
	cout << clsUtil::Tabs(5);	cout << "========================================\n";
	cout << clsUtil::Tabs(5);	cout << "         Currency Exchange Menu\n";
	cout << clsUtil::Tabs(5);	cout << "========================================\n";
	cout << clsUtil::Tabs(5);	cout << "   [1] List Currencies.\n";
	cout << clsUtil::Tabs(5);	cout << "   [2] Find Currency.\n";
	cout << clsUtil::Tabs(5);	cout << "   [3] Update Rate.\n";
	cout << clsUtil::Tabs(5);	cout << "   [4] Currency calculator.\n";
	cout << clsUtil::Tabs(5);	cout << "   [5] Main Menu.\n";
	cout << clsUtil::Tabs(5);	cout << "========================================\n\n";
	}

	static void _BackToCurrencyMenu() {
		cout << "Press to any key for back to currency menu ...\n";
		system("pause>0");

		system("cls");
		showCurrencyExchangeScreen();
	}

	static void _PerformOperation(enOptions choice) {
		switch (choice)
		{
		case clsCurrencyExchangeScreen::listCurrencies:
			system("cls");
			clsCurrenciesList::showCurrencyList();

			_BackToCurrencyMenu();
			break;
		case clsCurrencyExchangeScreen::findCurrency:
			system("cls");
			clsFindCurrencyScreen::showFindCurrencyScreen();

			_BackToCurrencyMenu();
			break;
		case clsCurrencyExchangeScreen::updateRate:
			system("cls");
			clsUpdateCurrencyScreen::showUpdateCurrencyScreen();

			_BackToCurrencyMenu();
			break;
		case clsCurrencyExchangeScreen::currencyCalculator:
			system("cls");
			clsCurrencyCalculatorScreen::showCurrencyCalculatorScreen();

			_BackToCurrencyMenu();
			break;
		case clsCurrencyExchangeScreen::mainMenu:
			system("cls");
			break;
		}
	}
public :
	static bool showCurrencyExchangeScreen() {
		if (!checkToAccess(clsBankUser::enPermissions::pCurrencyEx))
			return 0;

		clsScreen::_DrawScreenHeader("Currency Exchange Screen");
		_ShowMenu();

		_PerformOperation(enOptions(clsInputValidate::readNumberInRange(1, 5, "Choose what do you want to do [1,5]  ? ")));

		return 1;
	}
};

