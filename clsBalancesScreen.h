#pragma once
#include <iostream>
#include "clsUtil.h";
#include "clsBankClient.h";
class clsBalancesScreen : protected clsScreen
{
private:
	static void _PrintClientRecord(clsBankClient client) {

		cout << left << setw(20) << "| " + client.getAccountNumber() << left << setw(25)
			<< " | " + client.fullName();
		printf(" | %.2f\n", client.accountBalance);


	}

public:
	static void showClientsScreen() {
		vector < clsBankClient> vClientList = clsBankClient::getClientsList();

		//cout << "\n\t\t\t\t\t" << "Client List (" + to_string(vClientList.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader("Balances List Screen", "(" + to_string(vClientList.size()) + ") Client(s).");
		cout <<endl<< clsUtil::Tabs(2) << "________________________________________________________________________________________\n\n";
		cout << clsUtil::Tabs(3) << left << setw(20) << "| Account Number " << left << setw(25) << "| Full Name " << left << setw(10) << "| Balance " << endl;
		cout << clsUtil::Tabs(2) << "________________________________________________________________________________________\n\n";
		for (int i = 0; i < vClientList.size(); i++) {
			cout<<clsUtil::Tabs(3);_PrintClientRecord(vClientList[i]);
		}
		cout << clsUtil::Tabs(2) << "________________________________________________________________________________________\n";
		cout << clsUtil::Tabs(4) << "Total Balances : " << clsBankClient::getTotalBalances() << endl;
		cout << clsUtil::Tabs(3) <<"("+clsUtil::NumberToText(clsBankClient::getTotalBalances()) +")" << endl << endl;

	}

};

