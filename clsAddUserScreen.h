#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUtil.h"
#include "clsBankUser.h";

class clsAddUserScreen : protected clsScreen
{
private:
	static clsBankUser _ReadUser() {
		 string userName = clsInputValidate::readString("Enter User Name : ");

		 while (clsBankUser::IsUserExist(userName)) {
			 cout << "   -> This user is already Exist.\n";
			 userName = clsInputValidate::readString("Enter Another User Name : ");
		 }cout << endl;
		clsBankUser user = clsBankUser::getNewUser(userName);
		 user.FirstName = clsInputValidate::readString("Enter the First Name : ");
		 user.LastName = clsInputValidate::readString("Enter the Last Name  : ");
		 user.Phone = clsInputValidate::readString("Enter the Phone number : ");
		 user.Email = clsInputValidate::readString("Enter the Email : ");
		 user.password = clsInputValidate::readString("Enter the Password : ");
		 
	    user.permissions = _ReadPermissionsToSet();
		return user;
	}
	static int _ReadPermissionsToSet() {
		int per = 0;
		if (clsUtil::isContinue("Do you want to give full Access [1]:Yes ,[0]:No : "))
			per = -1;
		else {
			
			cout << "\nDo you want give access to : \n";
			if (clsUtil::isContinue("Show client List [1]:Yes ,[0]:No : "))
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
	static void showAddUserScreen() {

		clsScreen::_DrawScreenHeader("Add User Screen");


		clsBankUser user = _ReadUser();

		if (clsUtil::isContinue("Are you sure you want to add this user [1]:Yes , [0]:No ? ")) {
			clsBankUser::enSaveResults saveResult = user.save();
			switch (saveResult)
			{
			case clsBankUser::svSucceded:
				cout << "\nuser Added Successfully.\n";
				user.print();
				break;
			case clsBankUser::svFailedEmptyObject:
				cout << "\n user was not added because is empty user.\n";
				break;
			case clsBankUser::svFailedUserNameExists:
				cout << "\nuser was not added because this user already is exist in system.\n";
				break;
			}
		}

	}
};

