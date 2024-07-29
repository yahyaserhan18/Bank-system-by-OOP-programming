#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h";

class clsFindClientScreen:clsScreen
{

private:

	static string _ReadAccountNumber() {
		cout << clsUtil::Tabs(5); string AccountNumber = clsInputValidate::readString("Enter Account number : ");

			return AccountNumber;
	}

public:
	static bool FindClientScreen() {
		if (!checkToAccess(clsBankUser::enPermissions::pFindClinet))
			return 0;

		clsScreen::_DrawScreenHeader("Find Client Screen");


		string accNumber = _ReadAccountNumber();

		if (!clsBankClient::IsClientExist(accNumber))
		{
			cout << clsUtil::Tabs(5); cout << "   -> This Client is Not Exist.\n";
		}
		else
		{
			clsBankClient client = clsBankClient::Find(accNumber);
			cout << "Client is found :) \n";
			client.print();
		}


		return 1;

		
	}

};

