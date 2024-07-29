#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsBankUser.h";
using namespace std;


class clsListUsersScreen :clsScreen
{
private:
	static void _PrintUserRecord(clsBankUser user) {

		cout << left << setw(25) << " | " + user.fullName() << left << setw(25)
			<< "| " + user.Email << left << setw(15) << "| " + user.Phone << left << setw(25)
			<< "| " + user.userName << left << setw(10) << "| " + user.password << left << setw(10)<< " | " + to_string(user.permissions) << endl;
	}

public:
	static void showClientsScreen() {
		vector < clsBankUser> vUserList = clsBankUser::getUsersList();

		//cout << "\n\t\t\t\t\t" << "Client List (" + to_string(vClientList.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader("Clients List Screen", "(" + to_string(vUserList.size()) + ") Client(s).");
		cout << "\n_______________________________________________________________________________________________________________\n\n";
		cout << left << setw(25) << " | Full Name " << left << setw(25) << "| Email " << left << setw(15) << "| Phone " << left << setw(25) << "| UserName " << setw(10) << "| Password " << setw(10) << "| permissions " << endl;
		cout << "_______________________________________________________________________________________________________________\n\n";
		if (vUserList.size() == 0)
			cout << clsUtil::Tabs(6) << "No Users Available in the system.\n";
		else {
			for (int i = 0; i < vUserList.size(); i++) {
				_PrintUserRecord(vUserList[i]);
			}
			cout << "_______________________________________________________________________________________________________________\n";

		}

	}

};
