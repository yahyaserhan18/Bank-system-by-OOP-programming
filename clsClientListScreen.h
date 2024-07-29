#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankUser.h";

using namespace std;


class clsClientListScreen :clsScreen
{
private:
	static void _PrintClientRecord(clsBankClient client) {

		cout << left << setw(20) << "| " + client.getAccountNumber() << left << setw(25)
			<< " | " + client.fullName() << left << setw(15) << "| " + client.Phone << left << setw(25)
			<< " | " + client.Email << left << setw(10) << "| " + client.pinCode;
		printf(" | %.2f\n", client.accountBalance);


	}

public:
	static bool showClientsScreen() {
		if (!checkToAccess(clsBankUser::enPermissions::pShowClients))
			return 0;


		vector < clsBankClient> vClientList = clsBankClient::getClientsList();

		//cout << "\n\t\t\t\t\t" << "Client List (" + to_string(vClientList.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader("Clients List Screen", "(" + to_string(vClientList.size()) + ") Client(s).");
		cout << "\n_______________________________________________________________________________________________________________\n\n";
		cout << left << setw(20) << "| Account Number " << left << setw(25) << "| Full Name " << left << setw(15) << "| Phone " << left << setw(25) << "| Email " << setw(10) << "| Pin Code " << setw(10) << "| Balance " << endl;
		cout << "_______________________________________________________________________________________________________________\n\n";
		for (int i = 0; i < vClientList.size(); i++) {
			_PrintClientRecord(vClientList[i]);
		}
		cout << "_______________________________________________________________________________________________________________\n";
		

		return 1;
	}

};

