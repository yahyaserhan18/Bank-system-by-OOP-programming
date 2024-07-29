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
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsBalancesScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogScreen.h";

class clsTransactionsScreen : protected clsScreen 
{
private:
	enum enTransactionsMenuOptions { deposit = 1, Withdraw, totalBalance,transfer,transferLog, mainMenu };

	static void _ShowTransactionMenu() {
		cout << clsUtil::Tabs(5) << "=========================================================\n";
		cout << clsUtil::Tabs(8) << "Transactions Menu" << endl;
		cout << clsUtil::Tabs(5) << "=========================================================\n";
		cout << clsUtil::Tabs(6) << "[1] Deposit.\n";
		cout << clsUtil::Tabs(6) << "[2] Withdraw.\n";
		cout << clsUtil::Tabs(6) << "[3] Total Balances.\n";
		cout << clsUtil::Tabs(6) << "[4] Transfer.\n";
		cout << clsUtil::Tabs(6) << "[5] Transfer Log List.\n";
		cout << clsUtil::Tabs(6) << "[6] Main Menu.\n";
		cout << clsUtil::Tabs(5) << "=========================================================\n";

	}
	static void _GoBackToTransactionsMenu() {
		cout << " --->  Press any key for back to Transactions screen ...";
		system("pause>0");
		system("cls");
		showTransactionsMenu();
	}



	static void _ShowDepositScreen() {
		clsDepositScreen::showDepositScreen();
	}

	static void _ShowWithdrawScreen() {

		clsWithdrawScreen::showWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen() {
		clsBalancesScreen::showClientsScreen();
	}

	static void _ShowTransferScreen() {
		clsTransferScreen::showTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		clsTransferLogScreen::showTransferLogList();
	}


	static void _PerformMainMenuOption(enTransactionsMenuOptions choice) {

		switch (choice)
		{
		case enTransactionsMenuOptions::deposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::totalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::transfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::transferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;
		case enTransactionsMenuOptions::mainMenu:
			system("cls");
		}
	}

public:

	static bool showTransactionsMenu() {
		if (!checkToAccess(clsBankUser::enPermissions::pTransactions))
			return 0;

		clsScreen::_DrawScreenHeader("Transactions Screen");
		_ShowTransactionMenu();

		
		_PerformMainMenuOption(enTransactionsMenuOptions(clsInputValidate::readNumberInRange(1, 6, clsUtil::Tabs(5) + "Choose What do you want do [1,6] ? ", clsUtil::Tabs(5))));
	

		return 1;
	}





};



