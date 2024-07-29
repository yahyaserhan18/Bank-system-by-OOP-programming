#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUtil.h";
#include "clsInputValidate.h";
#include "clsBankUser.h";
#include "clsMainScreen.h";
#include "global.h";

using namespace std;
class clsLoginScreen: protected clsScreen
{
private:
	static void _Login() {
		string UserName;
		string Password;

		while (trialsNumber<3) {
			trialsNumber++;
			UserName = clsInputValidate::readString("Enter UserName : ");
			Password = clsInputValidate::readString("Enter Password : ");
			CurrentUser = clsBankUser::Find(UserName, Password);

			if (!CurrentUser.IsEmpty()) {
				CurrentUser.loadUserToLoginRegister();
				trialsNumber = 0;
				system("cls");
				clsMainScreen::showMainMenu();
				showLoginScreen();
			}
			else {
				system("cls");
				clsScreen::_DrawScreenHeader("Login Screen");
				if (trialsNumber == 3) {
					cout << "-> You are Locked after failed trails.\n";
				}
				else {
					cout << "Invalid userName/Password !\n";
					cout << "You have " << 3 - trialsNumber <<" trials to login." << endl<<endl;
				}
			}
		}
	}
public :
	static void showLoginScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("Login Screen");
		_Login();
	}

};

