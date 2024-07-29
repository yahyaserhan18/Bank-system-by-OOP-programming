#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUtil.h";
#include "clsInputValidate.h";
#include "clsCurrency.h";

class clsFindCurrencyScreen:clsScreen
{
private:

	static void _performCase1() {
		string code = clsInputValidate::readString("Please Enter Currency Code : ");
		clsCurrency currency = clsCurrency::FindByCode(code);
		if (currency.isEmpty())
			cout << "-> Error , Currency not found ):\n";
		else
		{
			cout << "Currency Found (:\n";
			currency.print();

		}
	}

	static void _performCase2() {
		string country = clsInputValidate::readString("Please Enter Currency Country : ");
		clsCurrency currency = clsCurrency::FindByCountry(country);

		if (currency.isEmpty())
			cout << "-> Error , Currency not found ):\n";
		else
		{
			cout << "Currency Found (:\n";
			currency.print();

		}

	}
	static void _performChoice(short choice) {

		switch (choice)
		{
			case 1:
			{
				_performCase1();
				break;
			}

			case 2:
			{
				_performCase2();
				break;
			}
		}
	}
	

public:
	static void showFindCurrencyScreen() {
		clsScreen::_DrawScreenHeader("Find Currency Screen");


		short choice = clsInputValidate::readNumberInRange(1, 2, "Find By : [1]-Code OR [2]-Country  ? ");
		
		_performChoice(choice);




	}
};

