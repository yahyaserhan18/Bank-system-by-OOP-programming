#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUtil.h";
#include "clsInputValidate.h";
#include "clsCurrency.h";

class clsCurrencyCalculatorScreen :clsScreen
{
private:
	static string _ReadCode(string message) {
		string code = clsInputValidate::readString(message);
		while (!clsCurrency::IsCurrencyExist(code)) {
			cout << "  -> Error , This Currency Code Not Exist.\n ";
			code = clsInputValidate::readString(message);
		}
		return code;
	}
	



public:
	static void showCurrencyCalculatorScreen() {

		do {
			system("cls");
			clsScreen::_DrawScreenHeader("Currency Calculator Screen");

			string curCode1 = _ReadCode("Please enter currency code1 : ");
			clsCurrency cur1 = clsCurrency::FindByCode(curCode1);cout << endl;

			string curCode2 = _ReadCode("Please enter currency code2 : ");
			clsCurrency cur2 = clsCurrency::FindByCode(curCode2);cout << endl;

			float amount = clsInputValidate::readFloatPositiveNumber("Enter Amount to Exchange : ");cout << endl;

			float result = clsCurrency::ExchangeAmountToOtherCurrency(cur1, cur2, amount);

			cur1.print();
			cout << amount <<" "<< cur1.getCurrencyCode() << " = " << result <<" "<< cur2.getCurrencyCode() << endl;


		} while (clsUtil::isContinue("Do you want to perform another calculation [1]:Yes ,[0]:No ? "));
	}
};


