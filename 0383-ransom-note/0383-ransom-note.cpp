class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int n = ransomNote.length();
        int m = magazine.length();
        if(n > m) return false;

        //frequency table
        int charCount[26] = {0};
        //count frequency of each character
        for(char c : magazine){
            charCount[c - 'a']++;
        }

        //is magazine has enough characters
        for(char c : ransomNote){
            if(--charCount[c - 'a'] < 0) return false;
        }

        return true;
    }
};