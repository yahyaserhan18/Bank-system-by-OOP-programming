#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h";


class clsDeleteClientScreen:clsScreen
{

private:
	static string _ReadAccountNumber() {
		cout << clsUtil::Tabs(5); string AccountNumber = clsInputValidate::readString("Enter Account number : ");

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << clsUtil::Tabs(5); cout << "   -> This Client is Not Exist.\n";
			cout << clsUtil::Tabs(5); AccountNumber = clsInputValidate::readString("Enter Another Account number : ");
		}
		return AccountNumber;
	}
public:
	static bool DeleteClientScreen() {
		if (!checkToAccess(clsBankUser::enPermissions::pDeleteClient))
			return 0;

		clsScreen::_DrawScreenHeader("Delete Client Screen");


		string accNumber = _ReadAccountNumber();
		clsBankClient client = clsBankClient::Find(accNumber);
		client.print();

		if (clsUtil::isContinue("Are you sure you want delete this client [1]:Yes , [0]:No ? ")) {
			if (client.Delete()) {
				cout << "Client Deleted successfully.\n";
				client.print();
			}
			else
				cout << "Client was not deleted.\n";
		}
		else {
			cout << "Ok Client NOt deleted.\n";
		}


		return 1;
	}

};

