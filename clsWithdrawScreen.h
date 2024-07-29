#pragma once
#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsWithdrawScreen :clsScreen
{
private:
	static string _ReadAccountNumber() {
		string AccountNumber = clsInputValidate::readString("Enter Account number : ");

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "   -> This Client is Not Exist.\n";
			AccountNumber = clsInputValidate::readString("Enter Another Account number : ");
		}
		return AccountNumber;
	}

	static float _ReadDepositAmount(clsBankClient client) {
		float WithDrawAmount = clsInputValidate::readFloatPositiveNumber("Please enter Withdraw amount : ");
		while (client.accountBalance < WithDrawAmount) {
			cout << "  -> Your money is not enough to withdraw this amount ...\n";
			 WithDrawAmount = clsInputValidate::readFloatPositiveNumber("Please enter another Withdraw amount : ");

		}

		return WithDrawAmount;
	}

public:
	static void showWithdrawScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("Withdraw Screen");

		string accountNumber = _ReadAccountNumber();

		clsBankClient client = clsBankClient::Find(accountNumber);cout << endl;
		client.print();

		float WithDrawAmount =_ReadDepositAmount(client);

		if (clsUtil::isContinue("Are you sure you want perform this transaction [1]:Yes , [0]:No? "))
		{

			if (client.Withdraw(WithDrawAmount))
			{
				cout << "Amount Withdrawed successfully.\n";
				cout << "New Balance : " << client.accountBalance << endl;
			}
			else
				cout << "You can not withdraw because you don't have enough money.\n";
		}
		else
			cout << "Ok ,transaction don't performed.\n";


	}
};



