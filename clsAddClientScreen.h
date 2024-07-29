#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h"

class clsAddClientScreen: protected clsScreen
{
private:
	static clsBankClient _ReadClient() {
		cout << clsUtil::Tabs(5); string AccountNumber = clsInputValidate::readString("Enter Account number : ");

		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << clsUtil::Tabs(5); cout << "   -> This Client is already Exist.\n";
			cout << clsUtil::Tabs(5); AccountNumber = clsInputValidate::readString("Enter Another Account number : ");
		}
		clsBankClient client = clsBankClient::getNewClient(AccountNumber);
		cout<<clsUtil::Tabs(5); client.FirstName = clsInputValidate::readString("Enter the First Name : ");
		cout<<clsUtil::Tabs(5); client.LastName = clsInputValidate::readString("Enter the Last Name  : ");
		cout<<clsUtil::Tabs(5); client.Phone = clsInputValidate::readString("Enter the Phone number : ");
		cout<<clsUtil::Tabs(5); client.Email = clsInputValidate::readString("Enter the Email : ");
		cout<<clsUtil::Tabs(5); client.pinCode = clsInputValidate::readString("Enter the Pin Code : ");
		cout<<clsUtil::Tabs(5); client.accountBalance = clsInputValidate::readDoubleNumber("Enter the Account Balance : ");
		return client;
	}
public :
	static bool AddNewClientScreen() {
		if (!checkToAccess(clsBankUser::enPermissions::pAddClient))
			return 0;

		clsScreen::_DrawScreenHeader("Add New Client Screen");


		clsBankClient client = _ReadClient();
		
		clsBankClient::enSaveResults saveResult = client.save();
		switch (saveResult)
		{
		case clsBankClient::svSucceded:
			cout << "\nClient Added Successfully.\n";
			client.print();
			break;
		case clsBankClient::svFailedEmptyObject:
			cout << "\n client was not added because is empty client.\n";
			break;
		case clsBankClient::svFailedAccountNumberExists:
			cout << "\nClient was not added because this client already is exist in system.\n";
			break;
		}
	
		return 1;
		
	}
};

