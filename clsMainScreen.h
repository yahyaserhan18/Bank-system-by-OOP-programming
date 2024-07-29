#pragma once
#include <iostream>
#include <vector>
#include "clsScreen.h";
#include "clsUtil.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include "clsClientListScreen.h";
#include "clsAddClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsManageUsersScreen.h";
#include "global.h";
#include "clsLoginRegisterScreen.h";
#include "clsCurrencyExchangeScreen.h";


class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOptions {listClients=1,addClient,deleteClient,updateClient,findClient,Transactions,manageUsers,loginRegister,currencyExchange ,logout };

	static void _ShowMainMenu() {
		cout << clsUtil::Tabs(5) << "=========================================================\n";
		cout << clsUtil::Tabs(8) << "Main Screen" << endl;
		cout << clsUtil::Tabs(5) << "=========================================================\n";
		cout << clsUtil::Tabs(6) << "[1] Show Client List\n";
		cout << clsUtil::Tabs(6) << "[2] Add New Client.\n";
		cout << clsUtil::Tabs(6) << "[3] Delete Client.\n";
		cout << clsUtil::Tabs(6) << "[4] Update Client Info.\n";
		cout << clsUtil::Tabs(6) << "[5] Find Client.\n";
		cout << clsUtil::Tabs(6) << "[6] Transactions.\n";
		cout << clsUtil::Tabs(6) << "[7] Mange Users.\n";
		cout << clsUtil::Tabs(6) << "[8] Login Register.\n";
		cout << clsUtil::Tabs(6) << "[9] Currency Exchange.\n";
		cout << clsUtil::Tabs(6) << "[10] Logout.\n";
		cout << clsUtil::Tabs(5) << "=========================================================\n";

	}
	static void _GoBackToMainMenu() {
		cout <<" --->  Press any key for back to main screen ...";
		system("pause>0");
		system("cls");
		showMainMenu();
	}

	static void _ShowAllClientsScreen() {
		clsClientListScreen::showClientsScreen();
	}

	static void _ShowAddClientScreen() {
		clsAddClientScreen::AddNewClientScreen();

	}

	static void _ShowDeleteClientScreen() {
		clsDeleteClientScreen::DeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::UpdateClientScreen();
	}

	static void _ShowFindClientScreen() {
		clsFindClientScreen::FindClientScreen();
	}

	static bool _ShowTransactionsScreen() {
		return clsTransactionsScreen::showTransactionsMenu();
	}

	static bool _ShowManageUsersScreen() {
		return clsManageUsersScreen::showManageUsersMenu();
	}

	static void _ShowLoginRegisterList() {
		clsLoginRegisterScreen::showLoginRegisterList();
	}

	static bool _ShowCurrencyExchangeScreen() {
		return clsCurrencyExchangeScreen::showCurrencyExchangeScreen();
	}

	static void _Logout() {
		CurrentUser = clsBankUser::Find("", "");
	}


	static void _PerformMainMenuOption(enMainMenuOptions choice) {

		switch (choice)
		{
		case clsMainScreen::listClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::addClient:
			system("cls");
			_ShowAddClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::deleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::updateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::findClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		case clsMainScreen::Transactions:
			system("cls");
			
			
			if(_ShowTransactionsScreen())
				showMainMenu();
			else
				_GoBackToMainMenu();
			
			break;
		case clsMainScreen::manageUsers:
			system("cls");
		
			if(_ShowManageUsersScreen())
				showMainMenu();
			else
				_GoBackToMainMenu();

	
			break;
		case clsMainScreen::loginRegister:
			system("cls");
			_ShowLoginRegisterList();
			
			_GoBackToMainMenu();


			break;
		case clsMainScreen::currencyExchange:
			system("cls");
			if(_ShowCurrencyExchangeScreen())
				showMainMenu();
			else 
				_GoBackToMainMenu();
			break;
		case clsMainScreen::logout:
			system("cls");
			_Logout();
			break;
		}
	}

public:

	static void showMainMenu() {
		clsScreen::_DrawScreenHeader("Main Screen");
		_ShowMainMenu();
	

		_PerformMainMenuOption(enMainMenuOptions(clsInputValidate::readNumberInRange(1, 10, clsUtil::Tabs(5) + "Choose What do you want do [1,10] ? ", clsUtil::Tabs(5))));
	}





};

