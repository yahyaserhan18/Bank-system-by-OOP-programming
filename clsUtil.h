#pragma once
#include <iostream>
#include <string>
#include "clsDate.h";

using namespace std;

class clsUtil
{

public:
    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }

    static string  GenerateKey(enCharType CharType = CapitalLetter)
    {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static  void ShuffleArray(int arr[], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    static bool isContinue(string message) {
        int answer = 0;
        cout << message;cin >> answer;
        while (answer!=0 && answer!=1) {
            cout << "Error, Out Range , \n" << message;cin >> answer;
        }
        return answer;
    }

    static string NumberToText(int number) {

        if (number == 0)
            return "";
        else if (number > 0 && number < 20) {
            string arr[] = { "","One", "Two", "Three", "Four", "Five",
            "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty" };

            return arr[number] + " ";
        }
        else if (number >= 20 && number < 100) {
            string arr[] = { "","", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety" };
            return arr[number / 10] + " " + NumberToText(number % 10) + " ";
        }
        else if (number >= 100 && number < 200) {
            return "One Hundred " + NumberToText(number % 100);
        }
        else if (number >= 200 && number < 1000) {
            return NumberToText(number / 100) + "Hundreds " + NumberToText(number % 100);
        }
        else if (number >= 1000 && number < 2000) {
            return "One thousand " + NumberToText(number % 1000);
        }
        else if (number >= 2000 && number < 1000000) {
            return  NumberToText(number / 1000) + "thousands " + NumberToText(number % 1000);
        }
        else if (number >= 1000000 && number <= 1999999) {
            return   "One Million " + NumberToText(number % 1000000);
        }
        else if (number >= 2000000 && number < 1000000000) {
            return  NumberToText(number / 1000000) + "Millions " + NumberToText(number % 1000000);
        }
        else if (number >= 1000000000 && number < 2000000000) {
            return   "One Billion " + NumberToText(number % 1000000000);
        }
        else {
            return    NumberToText(number / 1000000000) + "Billions " + NumberToText(number % 1000000000);
        }
    }


    static vector <string> LoadFilToStringVector(string fileName) {
        vector <string> vLines;

        fstream file;
        file.open(fileName, ios::in);
        if (file.is_open()) {
           
            string line = "";

            while (getline(file,line)) {
                if(line != "")
                    vLines.push_back(line);

            }
            file.close();
        }

        return vLines;
    }

   static int randomNumberInRange(int from, int to) {
        return rand() % (to - from + 1) + from;
    }
};

