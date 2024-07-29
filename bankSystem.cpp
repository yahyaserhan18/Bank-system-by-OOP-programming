#include <iostream>
#include <string>
#include <iomanip>
#include "clsDate.h";
#include "clsInputValidate.h";
#include "clsString.h";
#include  "clsUtil.h";

#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h";

using namespace std;

void  readClientInfo(clsBankClient& client) {
	client.FirstName = clsInputValidate::readString("Enter First Name : ");
	client.LastName = clsInputValidate::readString("Enter Last Name : ");
	client.Phone = clsInputValidate::readString("Enter Phone : ");
	client.Email = clsInputValidate::readString("Enter Email : ");
	client.pinCode = clsInputValidate::readString("Enter Pin code : ");
	client.accountBalance = clsInputValidate::readDoubleNumber("Enter Account Balance : ");
}



void updateClient() {
	string accNumber = clsInputValidate::readString("Please enter Account Number : ");
	while (true) {
		if (clsBankClient::IsClientExist(accNumber)) {
			clsBankClient client = clsBankClient::Find(accNumber);
			client.print();
			if (clsUtil::isContinue("Are you sure you want update this client [1]:Yes , [0]:No: "))
			{
				readClientInfo(client);
				client.save();
				cout << "\nclient updated successfully .\n\n";
				client.print();
			}
			break;
		}
		else {
			accNumber = clsInputValidate::readString("Account Number is not found ! , choose another one : ");
		}
	}
}

void AddNewClient() {
	cout << "---> Adding new Client : \n";
	string accNumber = clsInputValidate::readString("Enter Account Number : ");
	while (clsBankClient::IsClientExist(accNumber)) {
		accNumber = clsInputValidate::readString("Client already exist in system , Enter another Account Number : ");
	}
	clsBankClient newClient = clsBankClient::getNewClient(accNumber);
	readClientInfo(newClient);
	clsBankClient::enSaveResults saveResult = newClient.save();
	switch (saveResult)
	{
	case clsBankClient::svSucceded:
		cout << "\nAccoutn Added Successfully .\n";
		newClient.print();
		break;
	case clsBankClient::svFailedEmptyObject:
		cout << "\nError , Account was not saved because it's Empty.\n";
		break;
	case clsBankClient::svFailedAccountNumberExists:
		cout << "\nError , the client with this account number  is already Exists.\n";
		break;
	default:
		break;
	}
}

void deleteClient() {
	cout << "---> Deleting Client : \n";
	string accNumber = clsInputValidate::readString("Enter Account Number : ");
	while (!clsBankClient::IsClientExist(accNumber)) {
		accNumber = clsInputValidate::readString("Client is not exist in system , Enter another Account Number : ");
	}
	clsBankClient client = clsBankClient::Find(accNumber);

	client.print();
	if (clsUtil::isContinue("Do you want delete this client [1]:Yes , [0]:No ?")) {
		if (client.Delete())
		{
			cout << "\nClient deleted successfully .\n";
			client.print();
		}
		else
			cout << "\nClient don't delete because is not exist in system!\n";
	}
	else
		cout << "Ok , not deleted .\n";


}



void printClientRecordLine(clsBankClient& c) {
	cout << "| " << left << setw(20) << c.getAccountNumber();
	cout << "| " << left << setw(20) << c.fullName();
	cout << "| " << left << setw(15) << c.Phone;
	cout << "| " << left << setw(20) << c.Email;
	cout << "| " << left << setw(10) << c.pinCode;
	cout << "| " << left << setw(12) << c.accountBalance<<endl;
}
void showClientsList() {
	vector <clsBankClient> vList = clsBankClient::getClientsList();
	cout << endl<<clsUtil::Tabs(6) + "Clients List (" << vList.size() << ") Client(s).\n";
	cout << "\n___________________________________________________________________________";
	cout << "______________________________\n\n";
	cout << "| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(15) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pine code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n___________________________________________________________________________";
	cout << "______________________________\n\n";

	if (vList.size() == 0)
		cout << clsUtil::Tabs(6) << "No Clients Available in the system.\n";
	else {
		for (clsBankClient& c:vList) {
			printClientRecordLine(c);
		}
		cout << "\n___________________________________________________________________________";
		cout << "______________________________\n\n";

	}




};


void printClientRecordBalanceLine(clsBankClient& c) {
	cout << "| " << left << setw(20) << c.getAccountNumber();
	cout << "| " << left << setw(20) << c.fullName();
	cout << "| " << left << setw(12) << c.accountBalance << endl;
}
void showTotalBalances() {
	vector <clsBankClient> vList = clsBankClient::getClientsList();
	cout << endl << clsUtil::Tabs(4) + "Clients List (" << vList.size() << ") Client(s).\n";
	cout << "\n___________________________________________________________________________\n\n";

	cout << "| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n___________________________________________________________________________\n\n";


	if (vList.size() == 0)
		cout << clsUtil::Tabs(6) << "No Clients Available in the system.\n";
	else {
		for (clsBankClient& c : vList) {
			printClientRecordBalanceLine(c);
		}

		cout << "\n___________________________________________________________________________\n\n";

		float totalBalances = clsBankClient::getTotalBalances();
		cout << clsUtil::Tabs(2) <<"Total Balance : " << totalBalances << endl;
		cout << clsUtil::Tabs(2) << clsUtil::NumberToText(totalBalances)<< endl;
	}




};


int main()
{
	//updateClient();
	//AddNewClient();
	//deleteClient();
	//showClientsList();
	//showTotalBalances();


	//clsMainScreen::showMainMenu();
	clsLoginScreen::showLoginScreen();


	system("pause>0");
}

