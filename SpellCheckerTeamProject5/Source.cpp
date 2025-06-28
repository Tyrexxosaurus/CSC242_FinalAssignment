// SpellChecker.cpp

// Team: Tyler Reed, Joel Pila, Dupres Pina

// Description: Simple spell checker using dictionary file

#include <iostream>

#include <fstream>

#include <string>

#include <unordered_set>

#include <cctype>

#include <algorithm>

using namespace std;

// Tyler Reed – Load dictionary

unordered_set<string> loadDictionary(const string& filename) {

    ifstream file(filename);

    unordered_set<string> dictionary;

    string word;

    while (file >> word) {

        dictionary.insert(word);

    }

    return dictionary;

}

// Joel Pila – Clean word

string cleanWord(const string& word) {

    string cleaned;

    for (char ch : word) {

        if (isalpha(ch)) {

            cleaned += tolower(ch);

        }

    }

    return cleaned;

}

// Dupres Pina – Check spelling

void checkSpelling(const unordered_set<string>& dictionary, const string& filename) {

    ifstream file(filename);

    string word;

    while (file >> word) {

        string cleaned = cleanWord(word);

        if (!cleaned.empty() && dictionary.find(cleaned) == dictionary.end()) {

            cout << "Misspelled word: " << cleaned << endl;

        }

    }

}

// Main Function

int main() {

    string dictFile = "dictionary.txt";

    string inputFile = "input.txt";



    auto dictionary = loadDictionary(dictFile);

    checkSpelling(dictionary, inputFile);

    return 0;

}

