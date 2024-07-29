#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

using namespace std;






class clsString
{
private:
	string _StringValue;
	char _CharValue;
public:
	clsString() {

	}
	clsString(string value) {
		_StringValue = value;
	}
	clsString(char value) {
		_CharValue = value;
	}


	//get & set -> _Value
	string getStringValue() {
		return _StringValue;
	}
	void setStringValue(string value) {
		_StringValue = value;
	}
	_declspec(property(get = getStringValue, put = setStringValue))string stringValue;

	//get & set -> CharValue
	
	char getCharValue() {
		return _CharValue;
	}
	void setCharValue(char value) {
		_CharValue = value;
	}
	_declspec(property(get = getCharValue, put = setCharValue))char charValue;





	//1 :
	static string UpperFirstLeterOfEachFirstWord(string str) {

		bool isFirstChar = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ' && isFirstChar)
				str[i] = toupper(str[i]);

			isFirstChar = str[i] == ' ' ? true : false;
		}
		return str;
	}

	string UpperFirstLeterOfEachFirstWord() {
		return UpperFirstLeterOfEachFirstWord(_StringValue);
	}
	//2 :
	static string LowerFirstLeterOfEachFirstWord(string str) {

		bool isFirstChar = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ' && isFirstChar)
				str[i] = tolower(str[i]);

			isFirstChar = str[i] == ' ' ? true : false;
		}
		return str;
	}
	string LowerFirstLeterOfEachFirstWord() {
		return LowerFirstLeterOfEachFirstWord(_StringValue);
	}

	//3 :
	static string UpperString(string str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ')
				str[i] = toupper(str[i]);
		}
		return str;
	}
	string UpperString() {
		return UpperString(_StringValue);
	}

	//4 :
	static string LowerString(string str) {
		string str2 = str;
		for (int i = 0; i < str2.length(); i++) {
			if (str2[i] != ' ')
				str2[i] = tolower(str2[i]);
		}
		return str2;
	}
	string LowerString() {
		return LowerString(_StringValue);
	}
	
	//5 :
	static char invertCharCase(char  character) {
		char c;
		isupper(character) ? c = tolower(character) : c = toupper(character);
		return c;
	}
	char invertCharCase() {
		return invertCharCase(_CharValue);
	}

	//6 :
	static string invertAllCharsCase(string str) {
		for (int i = 0; i < str.length(); i++) {
			str[i] = invertCharCase(str[i]);
		}
		return str;
	}
	string invertAllCharsCase() {
		return invertAllCharsCase(_StringValue);
	}

	//7 :
	static int countCapitalLettersOfString(string str) {
		int count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (isupper(str[i]))
				count++;
		}
		return count;
	}
	int countCapitalLettersOfString() {
		return countCapitalLettersOfString(this->_StringValue);
	}

	//8 :
	static int countSmallLettersOfString(string str) {
		int count = 0;
		for (int i = 0; i < str.length(); i++) {
			if (islower(str[i]))
				count++;
		}
		return count;
	}
	int countSmallLettersOfString() {
		return countSmallLettersOfString(this->_StringValue);
	}

	//9 :
	static int countCharInString(string str, char character, bool caseIsImportant = true) {
		int counter = 0;
		for (int i = 0; i < str.length(); i++) {
			if (caseIsImportant)
			{
				if (str[i] == character)
					counter++;
			}
			else {
				if (toupper(str[i]) == toupper(character))
					counter++;
			}
		}
		return counter;
	}
	int countCharInString(char character, bool caseIsImportant = true) {
		return countCharInString(this->_StringValue, character, caseIsImportant);
	}
	//10 :
	static bool isVowelLetter(char character) {
		character = tolower(character);
		return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u');
	}
	bool isVowelLetter() {
		return isVowelLetter(this->_CharValue);
	}

	//11 :
	static int countVowelLetters(string str) {
		int counter = 0;
		for (int i = 0; i < str.length(); i++) {
			if (isVowelLetter(str[i]))
				counter++;
		}
		return counter;
	}
	int countVowelLetters() {
		return countVowelLetters(this->_StringValue);
	}

	//12 :
	static  vector <string> splitStringToVector(string str, string delim="#//#") {
		vector <string> vLines;
		short position = 0;
		string word = "";
		while ((position = str.find(delim)) != string::npos) {

			word = str.substr(0, position);
			//if (word != "")
			vLines.push_back(word);

			str.erase(0, position + delim.length());

		}

		if (str != "")
			vLines.push_back(str);

		return vLines;

	}
	vector <string> splitStringToVector(string delim) {
		return splitStringToVector(this->_StringValue, delim);
	}

	//13 :
	static int countWords(string str, string delim) {
		short position = 0;
		int counter = 0;
		string word = "";
		while ((position = str.find(delim)) != string::npos) {

			word = str.substr(0, position);
			if (word != "")
				counter++;

			str.erase(0, position + delim.length());

		}

		if (str != "")
			counter++;


		return counter;
	}
	int countWords(string delim) {
		return countWords(this->_StringValue, delim);
	}

	//14 :
	static string trimLeft(string str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != ' ')
				return str.substr(i, str.length() - i);
		}
		return "";

	}
	string trimLeft() {
		return trimLeft(this->_StringValue);
	}

	//15 :
	static string trimRight(string str) {

		for (int i = str.length() - 1; i > 0; i--) {
			if (str[i] != ' ')
				return str.substr(0, i + 1);
		}
		return "";

	}
	string trimRight() {
		return trimRight(this->_StringValue);
	}

	//16 :
	static string trim(string str) {
		return trimLeft(trimRight(str));
	}
	string trim() {
		return trim(this->_StringValue);
	}

	//17 :
	static string joinString(vector <string>& Vector, string delim) {
		string str = "";
		for (string& s : Vector) {
			str += s;
			if (s != Vector.back())
				str += delim;
		}
		return str;
	}

	//18 :
	static string joinString(string arr[], int len, string delim) {
		string str = "";
		for (int i = 0; i < len; i++) {
			str += arr[i];
			if (arr[i] != arr[len - 1])
				str += delim;
		}


		return str;
	}

	//19 :
	static vector <string> reverseVector(vector <string> v) {
		vector <string> vTemp;
		for (int i = v.size() - 1; i >= 0; i--) {
			vTemp.push_back(v[i]);
		}
		return vTemp;
		//for (string &line : vTemp) {
		//	v.push_back(line);
		//}
	}

	//20 :
	static string reverseWords(string str) {
		string tempStr = "";
		vector <string> vString = splitStringToVector(str, " ");

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin()) {
			iter--;
			tempStr += *iter + " ";
		}
		return tempStr.substr(0, tempStr.length() - 1);
	}
	string reverseWords() {
		reverseWords(this->_StringValue);
	}

	//21 :
	static string ReplaceWord(string str, string wordToReplace, string ReplaceTo, bool caseIsImportant = true) {

		vector <string> vString = splitStringToVector(str, " ");

		for (string& word : vString) {
			if (!caseIsImportant) {
				if (LowerString(word) == LowerString(wordToReplace))
					word = ReplaceTo;
			}
			else {
				if (word == wordToReplace)
					word = ReplaceTo;
			}
		}

		return joinString(vString, " ");

	}
	string ReplaceWord(string wordToReplace, string ReplaceTo, bool caseIsImportant = true) {
		return ReplaceWord(this->_StringValue, wordToReplace, ReplaceTo, caseIsImportant);
	}

	//22 :
	static string RemoveAllpucs(string str) {
		string result = "";
		//ispunct
		for (int i = 0; i < str.length(); i++) {
			if (!ispunct(str[i]))
				result += str[i];
		}
		return result;
	}
	string RemoveAllpucs() {
		return RemoveAllpucs(this->_StringValue);
	}
	//23 :
	static int length(string str) {
		return str.length();
	}
	int length() {
		return length(_StringValue);
	}
};

