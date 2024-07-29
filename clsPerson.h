#pragma once
#include <iostream>

using namespace std;


class clsPerson
{
private:
	string _FirstName="";
	string _LastName="";
	string _Email="";
	string _Phone="";
public:
	clsPerson(string firstName,string lastName,string email,string phone) {
		this->_FirstName = firstName;
		this->_LastName = lastName;
		this->_Email = email;
		this->_Phone = phone;
	}
	//get & set -> _FirstName
	string getFirstName() {
		return this->_FirstName;
	}
	void setFirstName(string firstName) {
		this->_FirstName = firstName;
	}
	_declspec(property(get = getFirstName, put = setFirstName))string FirstName;
	//get & set -> _LastName
	string getLastName() {
		return this->_LastName;
	}
	void setLastName(string lastName) {
		this->_LastName = lastName;
	}
	_declspec(property(get = getLastName, put = setLastName))string LastName;
	//get & set -> _Email
	string getEmail() {
		return this->_Email;
	}
	void setEmail(string email) {
		this->_Email = email;
	}
	_declspec(property(get = getEmail, put = setEmail))string Email;
	//get & set -> _Phone
	string getPhone() {
		return this->_Phone;
	}
	void setPhone(string phone) {
		this->_Phone = phone;
	}
	_declspec(property(get = getPhone, put = setPhone))string Phone;


	string fullName() {
		return this->_FirstName + " " + this->_LastName;
	}
};

