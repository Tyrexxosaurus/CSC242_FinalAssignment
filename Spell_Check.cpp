    //This is a placeholder provided to allow checkspelling to be verified -DP
string cleanWord(string word) {
    return word;
}


int checkspelling(set<string> dictionary, string filename){
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open file: " << filename << endl;
        return 1;
    }

    string word;
    while (inputFile >> word) {
        string clean_word = cleanWord(word);
        if (dictionary.find(clean_word) == dictionary.end()) {
            cout << "Misspelled word: " << word << endl;

        }
    }
    inputFile.close();

    return 0;
}


int main() {
    string dict_filename = "words.txt";
    string words_filename = "input.txt";

    set<string> dictionary = loadDictionary(dict_filename);
    checkspelling(dictionary, words_filename);

    return 0;
}
