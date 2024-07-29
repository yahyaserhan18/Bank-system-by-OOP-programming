#pragma once
#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsBankUser.h";
#include "global.h";
#include "clsDate.h";

using namespace std;


class clsScreen
{
public :
	static void _DrawScreenHeader(string title,string subTitle="") {
		cout <<endl<< clsUtil::Tabs(5) << "__________________________________________________________\n\n";
		cout << clsUtil::Tabs(8) << title;
		if(subTitle != "")
			cout << endl << clsUtil::Tabs(8)<<"  " << subTitle;

		cout << endl<<clsUtil::Tabs(5) << "__________________________________________________________\n\n";

		cout << clsUtil::Tabs(5) << "User : " << CurrentUser.userName << endl;
		cout << clsUtil::Tabs(5) << "Date : " << clsDate::GetSystemDateAsString() << endl<<endl;

	}

	static bool checkToAccess(clsBankUser::enPermissions perm) {
		if (CurrentUser.isHasPermissions(perm))
			return 1;
		else {
			system("cls");
			cout << "\t\t\t\t----------------------------------------------\n";
			cout << "\t\t\t\t  Error , You don't have access to this page \n";
			cout << "\t\t\t\t----------------------------------------------\n\n";
			return 0;
		}
	}
};

