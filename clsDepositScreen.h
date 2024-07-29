#pragma once

#include <iostream>
#include "clsScreen.h"

using namespace std;

class clsDepositScreen:clsScreen
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


public :
	static void showDepositScreen() {
				system("cls");
				clsScreen::_DrawScreenHeader("Deposit Screen");

				string accountNumber = _ReadAccountNumber();
				
				clsBankClient client = clsBankClient::Find(accountNumber);cout << endl;
				client.print();

				float depositAmount = clsInputValidate::readFloatPositiveNumber("Please enter deposit amount : ");

				if (clsUtil::isContinue("Are you sure you want perform this transaction [1]:Yes , [0]:No? "))
				{
					client.Deposit(depositAmount);
						cout << "Ammount Depositid successfully.\n";
						cout << "New Balance : " << client.accountBalance << endl;
				}
				else
					cout << "Ok ,transaction canceled.\n";
						

	}
};

