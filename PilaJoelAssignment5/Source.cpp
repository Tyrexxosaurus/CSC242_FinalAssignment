// MonoCipher.cpp
// Team: Tyler, Joel, Dupress
// Description: Basic monoalphabet cipher using keyword

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

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