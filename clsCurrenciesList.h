#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsCurrency.h";
#include <vector>
class clsCurrenciesList:clsScreen
{
private:
	static void _PrintCurrencyRecord(clsCurrency currency) {
		cout << left << setw(40) << "| " + currency.getCountry() << left << setw(10) << "| " + currency.getCurrencyCode() << left << setw(40) << "| " + currency.getCurrencyName()<< left << setw(20) << "| " + 
			to_string(currency.getRate()) << endl;
	
	}


public:
	static void showCurrencyList() {
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		//cout << "\n\t\t\t\t\t" << "Client List (" + to_string(vClientList.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader("Currencies List Screen", "(" + to_string(vCurrencies.size()) + ") Currency(s).");
		cout << "\n__________________________________________________________________________________________________________\n\n";
		cout << left << setw(40) << " | Country " << left << setw(10) << "| Code " << left << setw(40) << "| Name " << left << setw(20) << "| Rate/(1$) " << endl;
		cout << "__________________________________________________________________________________________________________\n\n";
		if (vCurrencies.size() == 0)
			cout << clsUtil::Tabs(6) << "No Currencies Available in the system.\n";
		else {
			for (int i = 0; i < vCurrencies.size(); i++) {
				_PrintCurrencyRecord(vCurrencies[i]);
			}
			cout << "__________________________________________________________________________________________________________\n\n";

		}
	}
};

