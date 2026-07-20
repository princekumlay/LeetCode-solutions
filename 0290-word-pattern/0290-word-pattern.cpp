#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // 1. Split the string s into individual words
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // 2. Base case: lengths must match
        if (pattern.length() != words.size()) {
            return false;
        }
        
        // 3. Two hash maps to track the bijection
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        // 4. Validate the mapping
        for (int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];
            
            // Check char -> word mapping
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }
            
            // Check word -> char mapping
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }
            
            // Build the mapping if it doesn't exist
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        
        return true;
    }
};