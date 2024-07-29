#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsListUsersScreen.h";
#include "clsAddUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";
class clsManageUsersScreen:clsScreen
{
private:
	enum enManageUsersMenuOptions { listUsers = 1, AddUser, deleteUser, updateUser, findUser, mainMenu };
	static void _ShowManageUsersMenu() {
		cout << clsUtil::Tabs(5) << "=========================================================\n";
		cout << clsUtil::Tabs(8) << "Main Screen" << endl;
		cout << clsUtil::Tabs(5) << "=========================================================\n";
		cout << clsUtil::Tabs(6) << "[1] List Users.\n";
		cout << clsUtil::Tabs(6) << "[2] Add New User.\n";
		cout << clsUtil::Tabs(6) << "[3] Delete User.\n";
		cout << clsUtil::Tabs(6) << "[4] Update User Info.\n";
		cout << clsUtil::Tabs(6) << "[5] Find User.\n";
		cout << clsUtil::Tabs(6) << "[6] Main Menu.\n";
		cout << clsUtil::Tabs(5) << "=========================================================\n";

	}
	static void _GoBackToManageUsersMenu() {
		cout << " --->  Press any key for back to Manage Users Screen ...";
		system("pause>0");
		system("cls");
		showManageUsersMenu();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions choice) {

		switch (choice)
		{
		case enManageUsersMenuOptions::listUsers:
			system("cls");
			clsListUsersScreen::showClientsScreen();
			_GoBackToManageUsersMenu();
			break;
		case enManageUsersMenuOptions::AddUser:
			system("cls");
			clsAddUserScreen::showAddUserScreen();

			_GoBackToManageUsersMenu();
			break;
		case enManageUsersMenuOptions::deleteUser:
			system("cls");
			clsDeleteUserScreen::showDeleteUserScreen();

			_GoBackToManageUsersMenu();
			break;
		case enManageUsersMenuOptions::updateUser:
			system("cls");
			clsUpdateUserScreen::showUpdateUserScreen();

			_GoBackToManageUsersMenu();
			break;
		case enManageUsersMenuOptions::findUser:
			system("cls");
			clsFindUserScreen::ShowFindClientScreen();

			_GoBackToManageUsersMenu();
			break;
		case enManageUsersMenuOptions::mainMenu:
			system("cls");
			break;
		}
	}
public:

	static bool showManageUsersMenu() {
		if (!checkToAccess(clsBankUser::enPermissions::pManageUsers))
			return 0;

		clsScreen::_DrawScreenHeader("Manage Users Screen");
		_ShowManageUsersMenu();


		_PerformManageUsersMenuOption(enManageUsersMenuOptions(clsInputValidate::readNumberInRange(1, 6, clsUtil::Tabs(5) + "Choose What do you want do [1,6] ? ", clsUtil::Tabs(5))));
	
		return 1;
	}

};

