#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h"
#include "clsBankUser.h";

class clsUpdateUserScreen : protected clsScreen
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

	static void _ReadUserForUpdate(clsBankUser& user) {
		
		user.FirstName = clsInputValidate::readString("Enter the First Name : ");
		user.LastName = clsInputValidate::readString("Enter the Last Name  : ");
		user.Phone = clsInputValidate::readString("Enter the Phone number : ");
		user.Email = clsInputValidate::readString("Enter the Email : ");
		user.password = clsInputValidate::readString("Enter the Password : ");

		user.permissions = _ReadPermissionsToSet();
	}
	static int _ReadPermissionsToSet() {
		int per = 0;
		if (clsUtil::isContinue("Do you want to give full Access [1]:Yes ,[0]:No : "))
			per = -1;
		else {

			cout << "\nDo you want give access to : \n";
			if (clsUtil::isContinue("Show client list [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pShowClients;
			if (clsUtil::isContinue("Add New Client [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pAddClient;
			if (clsUtil::isContinue("Delete Client [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pDeleteClient;
			if (clsUtil::isContinue("Update Client [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pUpdateClient;
			if (clsUtil::isContinue("Find Client [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pFindClinet;

			if (clsUtil::isContinue("Mange Users [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pManageUsers;

			if (clsUtil::isContinue("Transactions [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pTransactions;

			if (clsUtil::isContinue("Login Register List [1]:Yes ,[0]:No : "))
				per += clsBankUser::enPermissions::pLoginRegisterList;
		}

		return per;
	}

public:
	static void showUpdateUserScreen() {

		clsScreen::_DrawScreenHeader("Update User Screen");

		string userName = _ReadUserName();
		clsBankUser user = clsBankUser::Find(userName);
		cout << endl;
		user.print();cout << endl;

		if (clsUtil::isContinue("Are you sure you want to Update this user [1]:Yes , [0]:No ? ")) {
			cout << "\nUpdate User Info :\n";
			cout << "---------------------\n\n";
			_ReadUserForUpdate(user);
			clsBankUser::enSaveResults saveResult = user.save();
			switch (saveResult)
			{
			case clsBankUser::svSucceded:
				cout << "\nuser Updated Successfully.\n";
				user.print();
				break;
			case clsBankUser::svFailedEmptyObject:
				cout << "\n user was not Updated because is empty user.\n";
				break;
			}
		}
		else
			cout << "Ok , Update operation is Canceled.\n";

	}
};


