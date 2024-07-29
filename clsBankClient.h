#pragma once
#include <iostream>
#include <string>
#include "clsDate.h";
#include "clsInputValidate.h";
#include "clsString.h";
#include "clsUtil.h";
#include "clsPerson.h";
#include <vector>
#include "clsBankUser.h";
//#include "global.h";

class clsBankClient:public clsPerson 
{
private:	
	enum enMode{emptyMode , updateMode , AddNewMode};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;


	static clsBankClient _ConvertStringToClientObject(string line , string delim = "#//#") {
		vector <string> vRecord = clsString::splitStringToVector(line, delim);

		return clsBankClient(enMode::updateMode , vRecord[0], vRecord[1], vRecord[2], vRecord[3], vRecord[4], vRecord[5], stof(vRecord[6]));	
	}
	static void _LoadFileToClientsVector(vector <clsBankClient>& vClients , string fileName="clients.txt") {
		fstream clientsFile;
		clientsFile.open(fileName, ios::in);
		if (clientsFile.is_open()) {
			string line = "";
			while (getline(clientsFile,line)) {
				vClients.push_back(_ConvertStringToClientObject(line, "#//#"));
			}
		}
		clientsFile.close();
	}


	static string _ConvertClientObjectToString(clsBankClient client, string delim= "#//#") {
		string line = client.FirstName+delim;
		line += client.LastName+delim;
		line += client.Email + delim;
		line += client.Phone + delim;
		line += client._AccountNumber + delim;
		line += client.pinCode + delim;
		line += to_string(client.accountBalance);
		return line;
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::emptyMode, "", "", "", "", "", "", 0);
	}
	void _LoadClientsVectorToFile(vector <clsBankClient>& vClients) {
		fstream clientsFile;
		clientsFile.open("clients.txt", ios::out);
		if (clientsFile.is_open()) {
			for(clsBankClient & client : vClients)
				if(!client._MarkForDelete)
					clientsFile << _ConvertClientObjectToString(client) << endl;

			clientsFile.close();
		}
	
	}
	void _AddClientLineToFile(string line) {
		fstream clientsFile;
		clientsFile.open("clients.txt", ios::app);
		if (clientsFile.is_open()) {
			clientsFile << line << endl;
			clientsFile.close();
		}
	}

	void _Update() {

		vector <clsBankClient> vClients;
		_LoadFileToClientsVector(vClients);
		for (clsBankClient& client : vClients) {
			if (client._AccountNumber == this->_AccountNumber) {
				client = *this;
				break;
			}
		}
		_LoadClientsVectorToFile(vClients);
	}
	void _Add() {
		_AddClientLineToFile(_ConvertClientObjectToString(*this));
	}
	void _Delete() {
		vector <clsBankClient> vClients;
		_LoadFileToClientsVector(vClients);

		for (clsBankClient& client : vClients) {
			if (client._AccountNumber == this->_AccountNumber) {
				client._MarkForDelete = true;
			}
		}
		_LoadClientsVectorToFile(vClients);

		//my way :
		/*fstream clientsFile;
		clientsFile.open("clients.txt", ios::out);
		if (clientsFile.is_open()) {
			
			for (clsBankClient& client : vClients) {
				if (client._AccountNumber != this->_AccountNumber) {
					clientsFile << _ConvertClientObjectToString(client) << endl;
				}
			}

			clientsFile.close();
		}*/

	}


	string _PrepareTransferLogRecord(float amount , clsBankClient toClient,clsBankUser CurrentUser ,string delim = "#//#") {
		string nowDate = clsDate::GetSystemDateAsString();
		string nowTime = clsDate::GetSystemTime();

		return  nowDate + " - " + nowTime + delim + this->_AccountNumber + delim + toClient._AccountNumber + delim + to_string(amount)+
			delim+to_string(this->accountBalance)+delim + to_string(toClient.accountBalance) + delim + CurrentUser.userName;
		

	}


	bool _RegisterTransferToLogFile(float amount, clsBankClient toClient, clsBankUser correctUser) {
		string record = _PrepareTransferLogRecord(amount, toClient, correctUser);

		fstream LogFile;

		LogFile.open("transferLog.txt", ios::out | ios::app);

		if (LogFile.is_open()) {
			LogFile << record << endl;
			LogFile.close();

			return 1;
		}

		return 0;
	}

public:

	enum enSaveResults {svSucceded=1 , svFailedEmptyObject , svFailedAccountNumberExists};

	//constructor : 
	clsBankClient(enMode mode, string firstName, string lastName, string email, string phone,
		string accountNumber, string pinCode, float AccountBalance) :
		clsPerson(firstName, lastName, email, phone) {
		_Mode = mode;
		_AccountNumber = accountNumber;
		_PinCode = pinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty() {
		return this->_Mode == enMode::emptyMode;
	}

	//get -> _AccountNumber
	string getAccountNumber() {
		return this->_AccountNumber;
	}
	//get & set -> _PinCode 
	string getPinCode() {
		return this->_PinCode;
	}
	void setPinCode(string pinCode) {
		this->_PinCode = pinCode;
	}
	_declspec(property(get = getPinCode, put = setPinCode))string pinCode;
	//get & set -> _AccountBalance 
	float getAccountBalance() {
		return this->_AccountBalance;
	}
	void setAccountBalance(float AccountBalance) {
		this->_AccountBalance = AccountBalance;
	}
	_declspec(property(get = getAccountBalance, put = setAccountBalance))float accountBalance;


	void print() {
		cout << "\nClient Card : \n";
		cout << "----------------------------\n";
		cout << "First Name   : " << clsPerson::FirstName << endl;
		cout << "Last Name    : " << clsPerson::LastName << endl;
		cout << "Full Name    : " << clsPerson::fullName() << endl;
		cout << "Email        : " << clsPerson::Email << endl;
		cout << "Phone        : " << clsPerson::Phone << endl;
		cout << "Acc. Number  : " << this->_AccountNumber << endl;
		cout << "Password     : " << this->_PinCode << endl;
		cout << "Balance      : " << this->_AccountBalance << endl;
		cout << "----------------------------\n";
	}


	static clsBankClient Find(string accountNumber) {
		vector <clsBankClient> vClients;
		_LoadFileToClientsVector(vClients);

		for (clsBankClient& client : vClients) {
			if (client._AccountNumber == accountNumber) {
				return client;
			}
		}
		return _GetEmptyClientObject();

	}

	static clsBankClient Find(string accountNumber, string pinCode) {
		vector <clsBankClient> vClients;
		_LoadFileToClientsVector(vClients);

		for (clsBankClient& client : vClients) {
			if ((client._AccountNumber == accountNumber ) && (client._PinCode == pinCode)) {
				return client;
			}
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string accountNumber) {
		/*clsBankClient client = clsBankClient::Find(accountNumber);
		return (!client.IsEmpty());*/
		return !((clsBankClient::Find(accountNumber)).IsEmpty());
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
			if (IsClientExist(this->_AccountNumber))
				return enSaveResults::svFailedAccountNumberExists;

			_Add();
			this->_Mode = enMode::updateMode;

			return enSaveResults::svSucceded;

		}
	}
	bool Delete() {
		if (!IsClientExist(this->_AccountNumber))
			return 0;
		_Delete();
		*this = _GetEmptyClientObject();
		return 1;
	}
	static clsBankClient getNewClient(string accNumber) {
		clsBankClient newC = _GetEmptyClientObject();
		newC._Mode = enMode::AddNewMode;
		newC._AccountNumber = accNumber;
		return newC;
	}

	static vector <clsBankClient> getClientsList() {
		vector <clsBankClient> cList;
		_LoadFileToClientsVector(cList);
		return cList;
	}

	static float getTotalBalances() {
		vector <clsBankClient> vClients;
		_LoadFileToClientsVector(vClients);
		float total = 0;
		for (clsBankClient& c : vClients) {
			total += c.accountBalance;
		}
		return total;
	}

	void Deposit(double amount) {
		this->accountBalance += amount;
		this->save();
	}
	bool Withdraw(double amount) {
		if (this->accountBalance < amount)
			return 0;
		this->accountBalance -= amount;
		this->save();
		return 1;
	}


	bool transfer(float amount , clsBankClient & toClient , clsBankUser userName) {
		if (amount > this->accountBalance)
			return 0;

		Withdraw(amount);
		toClient.Deposit(amount);

		_RegisterTransferToLogFile(amount, toClient, userName);

		return 1;
	}
};

