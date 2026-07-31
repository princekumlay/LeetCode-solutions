class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort in descending order
        sort(freq.rbegin(), freq.rend());
        
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break; // No more characters left
            
            int pushesPerChar = (i / 8) + 1; // 1 push for first 8, 2 for next 8, etc.
            totalPushes += freq[i] * pushesPerChar;
        }
        
        return totalPushes;
    }
};