class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length()) return false;

        //brute force approach
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return  s == t;

        //optimized approach using hash table
        unordered_map<char, int> seen;
        for(char c: s){
            seen[c]++;
        }

        for(char c: t){
            seen[c]--;
            if(seen[c] < 0) return false;
        }

        //if any character value drops to less than 0 return false
        // for(auto pair: seen){
        //     if(pair.second < 0) return false;
        // }
        return true;
    }
};