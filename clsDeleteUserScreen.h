#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h"
#include "clsBankUser.h";

class clsDeleteUserScreen : protected clsScreen
{
private:
	static string _ReadUserName() {
		string userName = clsInputValidate::readString("Enter User name : ");

		while (!clsBankUser::IsUserExist(userName)) {
			cout << "   -> This User is Not Exist.\n";
			userName = clsInputValidate::readString("Enter Another User name : ");
		}
		return userName;
	}

public:
	static void showDeleteUserScreen() {

		clsScreen::_DrawScreenHeader("Delete User Screen");

		string accNumber = _ReadUserName();
		clsBankUser user = clsBankUser::Find(accNumber);
		cout << endl;
		user.print();
		cout << endl;
		if (clsUtil::isContinue("Are you sure you want to delete this user [1]:YES , [0]:NO ? ")) {
			if (user.Delete())
				cout << "User deleted successfully .\n";
			else
				cout << "User was not deleted .\n";
		}
		else
			cout << "Ok ,delete operation is Canceled.\n";
	}
};

