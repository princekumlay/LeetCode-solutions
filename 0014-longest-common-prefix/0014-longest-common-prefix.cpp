#include <vector>
#include <string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Iterate through each character of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            
            // Check this character against all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // Stop if out of bounds or character mismatch
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};