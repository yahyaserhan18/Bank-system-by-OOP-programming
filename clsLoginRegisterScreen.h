#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h";
#include "clsDate.h";
#include "clsUtil.h";
#include "clsBankUser.h";


using namespace std;


class clsLoginRegisterScreen:clsScreen
{
private:
	static void _PrintUserRecord(clsBankUser::stLoginRegisterRecord Record) {

		cout << left << setw(40) << " | " + Record.DateTime << left << setw(25) << "| " + Record .userName<< left << setw(15) <<
			"| "+ Record .password<< left << setw(10) << "| "+ to_string(Record.permissions) << endl;
	}

public:
	static bool showLoginRegisterList() {
		if(!clsScreen::checkToAccess(clsBankUser::enPermissions::pLoginRegisterList))
			return 0;


		vector <clsBankUser::stLoginRegisterRecord> vUserList = clsBankUser::GetLoginRegisterList();
		

		//cout << "\n\t\t\t\t\t" << "Client List (" + to_string(vClientList.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader("Login Register List Screen", "(" + to_string(vUserList.size()) + ") Client(s).");
		cout << "\n_______________________________________________________________________________________________________________\n\n";
		cout << left << setw(40) << " | Date/Time " << left << setw(25) << "| UserName " << left << setw(15) << "| Password " << left << setw(10) << "| Permissions " <<  endl;
		cout << "_______________________________________________________________________________________________________________\n\n";
		if (vUserList.size() == 0)
			cout << clsUtil::Tabs(6) << "No Login Registers Available in the system.\n";
		else {

			for (clsBankUser::stLoginRegisterRecord & Record : vUserList)
				_PrintUserRecord(Record);

		
			cout << "_______________________________________________________________________________________________________________\n";

		}
		return 1;
	}


};

