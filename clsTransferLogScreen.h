#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsString.h";
#include "clsDate.h";
#include "clsUtil.h";
#include "clsBankUser.h";

using namespace std;

class clsTransferLogScreen:clsScreen
{

private:
	static void _PrintUserRecord(clsBankUser::stTransferLogRecord Record) {

		cout << left << setw(30) << " | " + Record.DateTime << left << setw(15) << "| " + Record.SAcct << left << setw(15) <<
			"| " + Record.DAcct << left << setw(15) << "| " + to_string(Record.amount) <<
			left << setw(15) << "| " + to_string(Record.SBalance) << left << setw(15) << "| " + to_string(Record.DBalance)
			<< left << setw(15) << "| " + Record.userName
			<< endl;
	}

public:
	static void showTransferLogList() {

		vector <clsBankUser::stTransferLogRecord> vTransferLogList = clsBankUser::GetTransferLogList();


		//cout << "\n\t\t\t\t\t" << "Client List (" + to_string(vClientList.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader("Transfer Log List Screen", "(" + to_string(vTransferLogList.size()) + ") Client(s).");
		cout << "\n____________________________________________________________________________________________________________________\n\n";
		
		cout << left << setw(30) << " | Date/Time" << left << setw(15) << "| S.Acct"<< left << setw(15) <<
			"| D.Acct"<< left << setw(15) << "| Amount" <<
			left << setw(15) << "| S.Balance" << left << setw(15) << "| D.Balance"
			<< left << setw(15) << "| User"
			<< endl;
		
		cout << "____________________________________________________________________________________________________________________\n\n";
		if (vTransferLogList.size() == 0)
			cout << clsUtil::Tabs(6) << "No Transfer Log. Available in the system.\n";
		else {

			for (clsBankUser::stTransferLogRecord& Record : vTransferLogList)
				_PrintUserRecord(Record);


			cout << "____________________________________________________________________________________________________________________\n";

		}
	
	}

};

