#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h";
#include "clsScreen.h";
#include "clsBankUser.h"

class clsFindUserScreen:clsScreen
{

private:


public:
	static void ShowFindClientScreen() {

		clsScreen::_DrawScreenHeader("Find Client Screen");

		string userName = clsInputValidate::readString("Enter User Name : ");

		if (!clsBankUser::IsUserExist(userName)) {
			cout << "  -> This User is Not Exist.\n";
		}
		else {
			clsBankUser user = clsBankUser::Find(userName);
			cout << "\nuser is found :) \n";
			user.print();
		}



	}

};

