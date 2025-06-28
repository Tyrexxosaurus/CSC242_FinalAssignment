/* ---------------------------------------------------------------------------
/** I attest that this following code represents my own work and is subject to
/** the plagiarism policy found in the course syllabus.
/**
/** Class: 	CSC 242
/** Assignment: 	Lesson # 5
/** File: 	Load_Dictionary.cpp
/** Description: This function will load the dictionary.
/**
/** Author: 	Tyler Reed, Joel Pila, Dupres Pina
/** Date: 	27Jun25
/** -------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;


std::set<std::string> loadDictionary(const std::string& filename) 
{
    std::ifstream file(filename); 
    std::set<std::string> dictionary; 

    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file: " << filename << std::endl;
        return dictionary;
    }

    std::string word;
    while (file >> word) 
    {
        dictionary.insert(word); 
    }

    file.close(); 
    return dictionary; 
}

int main() {
    std::string filename = "dictionary";
    std::set<std::string> dictionary = loadDictionary(filename);

    std::cout << "Words in dictionary:\n";
    for (const auto& word : dictionary)
    {
        std::cout << word << "\n";
    }

    return 0;
}