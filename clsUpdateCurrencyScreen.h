#pragma once
#include <iostream>
#include "clsCurrency.h";
#include "clsInputValidate.h";
#include "clsUtil.h";
#include "clsScreen.h";
class clsUpdateCurrencyScreen:clsScreen
{


public:
	static void showUpdateCurrencyScreen() {

		clsScreen::_DrawScreenHeader("Update Curreny Screen");
		string currCode = clsInputValidate::readString("Please enter currency code : ");
		while (!clsCurrency::IsCurrencyExist(currCode)) {
			cout << " -> Error , This Currency not found.\n";
			 currCode = clsInputValidate::readString("Please enter currency code : ");

		}

		clsCurrency currency = clsCurrency::FindByCode(currCode);
		currency.print();
		if (clsUtil::isContinue("Are you sure you want to update this currency [1]:Yes , [0]:No  ? ")) {
			cout << "\nUpdate Currency  Rate :\n";
			cout << "----------------------------\n";
			float newRate = clsInputValidate::readFloatPositiveNumber("Enter New Rate : ");
			currency.UpdateRate(newRate);

			cout << "\n\nCurrency Rate updated successfully.\n\n";
			currency.print();

		}
		else
			cout << "Ok , Operation is Canceled.\n";

	}
};

