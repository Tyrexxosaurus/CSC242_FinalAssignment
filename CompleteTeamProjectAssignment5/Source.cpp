// MonoCipher.cpp
// Team: Tyler Reed, Joel Pila, Dupres Pina
// Description: Basic monoalphabet cipher using keyword

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

// Member 1: Tyler Reed - Generates cipher alphabet based on keyword
unordered_map<char, char> generateCipher(const string& keyword, bool decrypt) {
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
    for (int i = 0; i < 26; ++i) {
        char plain = 'A' + i;
        char coded = cipherAlpha[i];
        if (decrypt) {
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

// Member 2: Joel Pila - Processes the text file
void processFile(const string& input, const string& output, const unordered_map<char, char>& map) {
    ifstream in(input);
    ofstream out(output);
    char ch;
    while (in.get(ch)) {
        if (isalpha(ch)) {
            out.put(map.at(ch));
        }
        else {
            out.put(ch);
        }
    }
}

// Member 3: Dupres Pina - Manages command-line and execution
int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: cipher -[e|d] -kKEY input.txt output.txt\n";
        return 1;
    }

    bool decrypt = (string(argv[1]) == "-d");
    string keyword = argv[2];
    string inFile = argv[3];
    string outFile = argv[4];

    auto cipherMap = generateCipher(keyword, decrypt);
    processFile(inFile, outFile, cipherMap);

    cout << (decrypt ? "Decryption" : "Encryption") << " complete.\n";
    return 0;
}