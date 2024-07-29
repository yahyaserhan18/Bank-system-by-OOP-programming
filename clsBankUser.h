
#pragma once
#include <iostream>
#include <string>
#include "clsDate.h";
#include "clsInputValidate.h";
#include "clsString.h";
#include "clsUtil.h";
#include "clsPerson.h";
#include <vector>
#include <fstream>
#include "clsUtil.h";


class clsBankUser :public clsPerson
{
private:
	enum enMode { emptyMode, updateMode, AddNewMode };
	enMode _Mode;
	string _UserName;
	string _Password;
    int _Permissions;
	bool _MarkForDelete = false;


	static clsBankUser _ConvertStringToUserObject(string line, string delim = "#//#") {
		vector <string> vRecord = clsString::splitStringToVector(line, delim);

		return clsBankUser(enMode::updateMode, vRecord[0], vRecord[1], vRecord[2], vRecord[3], vRecord[4], clsUtil::DecryptText(vRecord[5]), stoi(vRecord[6]) );
	}

	static void _LoadFileToUsersVector(vector <clsBankUser>& vUsers, string fileName = "users.txt") {
		fstream UsersFile;
		UsersFile.open(fileName, ios::in);
		if (UsersFile.is_open()) {
			string line = "";
			while (getline(UsersFile, line)) {
				if(line!="")
					vUsers.push_back(_ConvertStringToUserObject(line, "#//#"));
			}
		}
		UsersFile.close();
	}


	 string _ConvertUserObjectToString(clsBankUser user, string delim = "#//#") {
		string line = user.FirstName + delim;
		line += user.LastName + delim;
		line += user.Email + delim;
		line += user.Phone + delim;
		line += user.userName + delim;
		line += clsUtil::EncryptText(user.password) + delim;
		line += to_string(user.permissions);
		return line;
	}

	static clsBankUser _GetEmptyUserObject() {
		return clsBankUser(enMode::emptyMode, "", "", "", "", "", "",0);
	}
	void _LoadUsersVectorToFile(vector <clsBankUser>& vUsers) {
		fstream UsersFile;
		UsersFile.open("users.txt", ios::out);
		if (UsersFile.is_open()) {
			for (clsBankUser& user : vUsers)
				if (!user._MarkForDelete)
					UsersFile << _ConvertUserObjectToString(user) << endl;

			UsersFile.close();
		}

	}
	void _AddUserLineToFile(string line) {
		fstream UsersFile;
		UsersFile.open("users.txt", ios::app);
		if (UsersFile.is_open()) {

			UsersFile << line << endl;
			UsersFile.close();
		}
	}

	void _Update() {

		vector <clsBankUser> vUsers;
		_LoadFileToUsersVector(vUsers);
		for (clsBankUser& user : vUsers) {
			if (user.userName == this->_UserName) {
				user = *this;
				break;
			}
		}
		_LoadUsersVectorToFile(vUsers);
	}
	void _Add() {
		_AddUserLineToFile(_ConvertUserObjectToString(*this));
	}
	void _Delete() {
		vector <clsBankUser> vUsers;
		_LoadFileToUsersVector(vUsers);

		for (clsBankUser& user : vUsers) {
			if (user.userName == this->_UserName) {
				user._MarkForDelete = true;
			}
		}
		_LoadUsersVectorToFile(vUsers);

	}




	 string _PrepareLoginRegisterRecord(string delim = "#//#") {
		string nowDate = clsDate::GetSystemDateAsString();
		string nowTime = clsDate::GetSystemTime();

		return  nowDate + " - " + nowTime + delim + this->userName + delim + clsUtil::EncryptText(this->password) + delim + to_string(this->permissions);

	}

	 struct stLoginRegisterRecord;

	 static  stLoginRegisterRecord  _ConvertRecordToLoginRegisterStruct(string line) {
		 vector <string> vRecord = clsString::splitStringToVector(line, "#//#");
		 stLoginRegisterRecord stLoginReg;
		 stLoginReg.DateTime = vRecord[0];
		 stLoginReg.userName = vRecord[1];
		 stLoginReg.password = clsUtil::DecryptText(vRecord[2]);
		 stLoginReg.permissions =stoi(vRecord[3]);

		 return stLoginReg;
	}

	 struct stTransferLogRecord;

	 static stTransferLogRecord _ConvertRecordToTransferLogStruct(string line) {
		 vector <string> vRecord = clsString::splitStringToVector(line, "#//#");
		 stTransferLogRecord stTransferLog;


		 stTransferLog.DateTime = vRecord[0];
		 stTransferLog.SAcct = vRecord[1];
		 stTransferLog.DAcct = vRecord[2];
		 stTransferLog.amount = stof(vRecord[3]);
		 stTransferLog.SBalance = stof(vRecord[4]);
		 stTransferLog.DBalance = stof(vRecord[5]);
		 stTransferLog.userName = vRecord[6];

		 return stTransferLog;
	 }
public:

	enum enSaveResults { svSucceded = 1, svFailedEmptyObject, svFailedUserNameExists };
	 enum enPermissions { pShowClients = 1, pAddClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClinet = 16, pTransactions = 32, pManageUsers = 64 , pLoginRegisterList=128,pCurrencyEx=256, pFullAccess = -1 };

	 struct stLoginRegisterRecord {
		 string DateTime;
		 string userName;
		 string password;
		 int    permissions;
	 };
	 struct stTransferLogRecord {
		 string DateTime;
		 string SAcct;
		 string DAcct;
		 float amount;
		 float SBalance;
		 float DBalance;
		 string userName;
	 };

	//constructor : 
	clsBankUser(enMode mode, string firstName, string lastName, string email, string phone,
		 string userName, string password , int permissions) :
		clsPerson(firstName, lastName, email, phone) {
		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permissions = permissions;
	}

	bool IsEmpty() {
		return this->_Mode == enMode::emptyMode;
	}


	//get & set -> _UserName 
	string getUserName() {
		return this->_UserName;
	}
	void setUserName(string userName) {
		this->_UserName = userName;
	}
	_declspec(property(get = getUserName, put = setUserName))string userName;
	//get & set -> _Password 
	string getPassword() {
		return this->_Password;
	}
	void SetPassword(string pass) {
		this->_Password = pass;
	}
	_declspec(property(get = getPassword, put = SetPassword))string password;
	//get & set -> _Permissions
	int getPermissions() {
		return this->_Permissions;
	}
	void setPermissions(int permissions) {
		this->_Permissions = permissions;
	}
	_declspec(property(get = getPermissions, put = setPermissions))int permissions;


	void print() {
		cout << "\nUser Card : \n";
		cout << "----------------------------\n";
		cout << "First Name   : " << clsPerson::FirstName << endl;
		cout << "Last Name    : " << clsPerson::LastName << endl;
		cout << "Full Name    : " << clsPerson::fullName() << endl;
		cout << "Email        : " << clsPerson::Email << endl;
		cout << "Phone        : " << clsPerson::Phone << endl;
		cout << "UserName     : " << this->_UserName << endl;
		cout << "Password     : " << this->_Password << endl;
		cout << "permission   : " << this->permissions<< endl;
		cout << "----------------------------\n";
	}


	static clsBankUser Find(string userName) {
		vector <clsBankUser> vUsers;
		_LoadFileToUsersVector(vUsers);

		for (clsBankUser& user : vUsers) {
			if (user.userName == userName) {
				return user;
			}
		}
		return _GetEmptyUserObject();

	}
	static clsBankUser Find(string userName,string password) {
		vector <clsBankUser> vUsers;
		_LoadFileToUsersVector(vUsers);

		for (clsBankUser& user : vUsers) {
			if (user.userName == userName && user.password == password) {
				return user;
			}
		}
		return _GetEmptyUserObject();

	}

	static bool IsUserExist(string userName) {

		return !((clsBankUser::Find(userName)).IsEmpty());
	}

	enSaveResults save() {

		switch (this->_Mode)
		{
		case enMode::emptyMode:
			return enSaveResults::svFailedEmptyObject;
		case enMode::updateMode:
			_Update();
			return enSaveResults::svSucceded;
		case enMode::AddNewMode:
			if (IsUserExist(this->userName))
				return enSaveResults::svFailedUserNameExists;

			_Add();
			this->_Mode = enMode::updateMode;

			return enSaveResults::svSucceded;
			break;
		}
	}

	bool Delete() {
		if (!IsUserExist(this->userName))
			return 0;
		_Delete();
		*this = _GetEmptyUserObject();
		return 1;
	}

	static clsBankUser getNewUser(string userName) {
		clsBankUser newC = _GetEmptyUserObject();
		newC._Mode = enMode::AddNewMode;
		newC.userName = userName;
		return newC;
	}

	static vector <clsBankUser> getUsersList() {
		vector <clsBankUser> user;
		_LoadFileToUsersVector(user);
		return user;
	}

	
	bool isHasPermissions(enPermissions option) {
		if ( this->permissions == enPermissions::pFullAccess)
			return true;

		return ((this->permissions & int(option)) == int(option));


	}

	bool loadUserToLoginRegister(string delim="#//#") {
		string record = _PrepareLoginRegisterRecord();

		fstream RegisterFile;

		RegisterFile.open("loginRegister.txt",ios::out | ios::app);

		if (RegisterFile.is_open()) {
			RegisterFile << record << endl;
			RegisterFile.close();

			return 1;
		}
		
		return 0;
	}


	static vector <stLoginRegisterRecord> GetLoginRegisterList() {

		vector <stLoginRegisterRecord> vRecords;
		fstream file;
		file.open("loginRegister.txt", ios::in);

		if (file.is_open()) {
			string line = "";
			while (getline(file, line)) {
				vRecords.push_back(_ConvertRecordToLoginRegisterStruct(line));
			}
		}

		return vRecords;
	}

	static vector <stTransferLogRecord> GetTransferLogList() {

		vector <stTransferLogRecord> vRecords;
		fstream file;
		file.open("transferLog.txt", ios::in);

		if (file.is_open()) {
			string line = "";
			while (getline(file, line)) {
				vRecords.push_back(_ConvertRecordToTransferLogStruct(line));
			}
		}

		return vRecords;
	}



};



