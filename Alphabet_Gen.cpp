/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Lesson # 5
** File: 	Alphabet_Gen.cpp
** Description: This function generates a cipher alphabet based on a keyword
**
** Author: 	Tyler Reed, Joel Pila, Dupres Pina
** Date: 	26Jun25
** -------------------------------------------------------------------------*/


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<char, char> generateCipher(const string& keyword, bool decrypt) 
{
    unordered_set<char> seen;
    string cipherAlpha;

    for (char ch : keyword) {
        ch = toupper(ch);
        if (isalpha(ch) && seen.find(ch) == seen.end()) {
            cipherAlpha += ch;
            seen.insert(ch);
        }
    }

    for (char ch = 'Z'; ch >= 'A'; --ch) {
        if (seen.find(ch) == seen.end()) {
            cipherAlpha += ch;
        }
    }

    unordered_map<char, char> cipherMap;
    for (int i = 0; i < 26; ++i) 
    {
        char plain = 'A' + i;
        char coded = cipherAlpha[i];
        if (decrypt) 
        {
            cipherMap[coded] = plain;
            cipherMap[tolower(coded)] = tolower(plain);
        }
        else {
            cipherMap[plain] = coded;
            cipherMap[tolower(plain)] = tolower(coded);
        }
    }

    return cipherMap;
}