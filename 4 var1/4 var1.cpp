#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
using namespace std;

vector<string> fillArray(string filename) {
    ifstream file(filename);
    vector<string> words;
    string word;
    while (file >> word) {
        words.push_back(word);
    }
    file.close();
    return words;
}

string toLower(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

string getCanonicalForm(const string& word) {
    string canonical = toLower(word);
    sort(canonical.begin(), canonical.end());
    return canonical;
}

bool isAnagram(const string& word1, const string& word2) {
    if (word1.length() != word2.length()) {
        return false;
    }
    return getCanonicalForm(word1) == getCanonicalForm(word2);
}

void printAnagrams(vector<string> words, string input) {
    bool found = false;
    for (const string& word : words) {
        if (isAnagram(word, input) && input!=word) {
            cout << word << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No anagrams found." << endl;
    }
}

int main() {
    vector<string> words = fillArray("file.txt");
    string input;
    cout << "Enter a word: ";
    cin >> input;
    cout << "Anagrams of \"" << input << "\":" << endl;
    printAnagrams(words, input);
    return 0;
}