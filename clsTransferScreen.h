#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsUtil.h";
using namespace std;



class clsTransferScreen:clsScreen
{
	static clsBankClient _ReadClient(string message) {
		string accNumber = clsInputValidate::readString(message);
		while (!clsBankClient::IsClientExist(accNumber)) {
			cout << "  --> Error : Client Not Found!\n";
			accNumber = clsInputValidate::readString(message);
		}
		return clsBankClient::Find(accNumber);

	}

	static void _PrintSummary(clsBankClient client) {
		cout << endl << "Client Card : \n";
		cout << "___________________________\n\n";
		cout << "Full Name   : " << client.fullName() << endl;
		cout << "Acc. Number : " << client.getAccountNumber() << endl;
		cout << "Balance     : " << client.accountBalance << endl;
		cout << "___________________________\n";

	}
	
	static float _ReadAmount(clsBankClient fromClient) {
		float amount = clsInputValidate::readFloatPositiveNumber("Enter transfer amount : ");
		while (amount > fromClient.accountBalance) {
			cout << "  --> Error : " << fromClient.getAccountNumber() << " Client don't have enough Money to transfer!\n";
			amount = clsInputValidate::readFloatPositiveNumber("Enter Another transfer amount : ");
		}
		return amount;
	}

public:
	static void showTransferScreen() {
		_DrawScreenHeader("Transfer Screen");
		clsBankClient fromClient = _ReadClient("Please Enter Account Number to transfer From : ");
		cout << endl;
		_PrintSummary(fromClient);

		cout << endl;

		clsBankClient toClient = _ReadClient("Please Enter Account Number to transfer To : ");
		cout << endl;
		_PrintSummary(toClient);

		cout << endl << endl;
		float amount = _ReadAmount(fromClient);

		if (clsUtil::isContinue("Are you sure you want to perform this operation [1]:Yes , [0]:No  ? "))
		{
			/*fromClient.accountBalance -= amount;
			toClient.accountBalance += amount;
			fromClient.save();
			toClient.save();*/

			if (fromClient.transfer(amount, toClient,CurrentUser)) {
				cout << "Transfer Done successfully.\n\n";
				cout << "-- After Transfer -- \n";
				_PrintSummary(fromClient);
				_PrintSummary(toClient);
			}
			else
				cout << "  --> Transfer Failed : " << fromClient.getAccountNumber() << " Client don't have enough Money to transfer!\n";
		}
		else
			cout << "Ok, Operation is canceled.\n";
	}
};

