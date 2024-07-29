#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h";



class clsUpdateClientScreen:clsScreen
{
private:
	static void _ReadClient(clsBankClient &client) {
		
		cout << clsUtil::Tabs(5); client.FirstName = clsInputValidate::readString("Enter the First Name : ");
		cout << clsUtil::Tabs(5); client.LastName = clsInputValidate::readString("Enter the Last Name  : ");
		cout << clsUtil::Tabs(5); client.Phone = clsInputValidate::readString("Enter the Phone number : ");
		cout << clsUtil::Tabs(5); client.Email = clsInputValidate::readString("Enter the Email : ");
		cout << clsUtil::Tabs(5); client.pinCode = clsInputValidate::readString("Enter the Pin Code : ");
		cout << clsUtil::Tabs(5); client.accountBalance = clsInputValidate::readDoubleNumber("Enter the Account Balance : ");
	}
	static string _ReadAccountNumber() {
		cout << clsUtil::Tabs(5); string AccountNumber = clsInputValidate::readString("Enter Account number : ");

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << clsUtil::Tabs(5); cout << "   -> This Client is Not Exist.\n";
			cout << clsUtil::Tabs(5); AccountNumber = clsInputValidate::readString("Enter Another Account number : ");
		}
		return AccountNumber;
	}
public:
	static bool UpdateClientScreen() {
		if (!checkToAccess(clsBankUser::enPermissions::pUpdateClient))
			return 0;

		clsScreen::_DrawScreenHeader("Update Client Screen");

		string accNumber = _ReadAccountNumber();
		clsBankClient client = clsBankClient::Find(accNumber);
		client.print();

		if (clsUtil::isContinue("Are you sure you want update this client [1]:Yes , [0]:No ? ")) {
			 _ReadClient(client);

			 clsBankClient::enSaveResults saveResult = client.save();
			 switch (saveResult)
			 {
			 case clsBankClient::svSucceded:
				 cout << "\nClient Updated Successfully.\n";
				 client.print();
				 break;
			 case clsBankClient::svFailedEmptyObject:
				 cout << "\n client was not Updated because is empty client.\n";
				 break;
			 }

		}
		return 1;

	}

};

