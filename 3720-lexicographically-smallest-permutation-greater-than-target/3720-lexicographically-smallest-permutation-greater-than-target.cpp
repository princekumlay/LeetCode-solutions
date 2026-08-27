#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Try to match target as far left-to-right as possible
        int matchLen = 0;
        while (matchLen < n && count[target[matchLen] - 'a'] > 0) {
            count[target[matchLen] - 'a']--;
            matchLen++;
        }

        // Backtrack to find the rightmost index where we can place a strictly larger character
        for (int i = matchLen; i >= 0; i--) {
            // If i == n, we matched all characters so s == target, but we need strictly greater.
            // Backtrack one step to bump a character.
            if (i < n) {
                char targetChar = target[i];
                // Find the smallest character strictly greater than target[i]
                for (int c = targetChar - 'a' + 1; c < 26; c++) {
                    if (count[c] > 0) {
                        // Construct the answer
                        string res = target.substr(0, i);
                        res += (char)('a' + c);
                        count[c]--;

                        // Fill the remaining suffix greedily with smallest available chars
                        for (int ch = 0; ch < 26; ch++) {
                            while (count[ch] > 0) {
                                res += (char)('a' + ch);
                                count[ch]--;
                            }
                        }
                        return res;
                    }
                }
            }

            // Backtrack: restore target[i-1] into available count pool
            if (i > 0) {
                count[target[i - 1] - 'a']++;
            }
        }

        return "";
    }
};