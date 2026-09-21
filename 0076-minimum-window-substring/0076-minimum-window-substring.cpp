

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for target string t
        std::vector<int> targetCount(128, 0);
        for (char c : t) {
            targetCount[c]++;
        }

        // Count unique characters required to match
        int required = 0;
        for (int count : targetCount) {
            if (count > 0) required++;
        }

        std::vector<int> windowCount(128, 0);
        int formed = 0;
        
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minLeft = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            // Check if frequency of current character matches target frequency
            if (targetCount[c] > 0 && windowCount[c] == targetCount[c]) {
                formed++;
            }

            // Contract window from the left as long as it contains all required characters
            while (left <= right && formed == required) {
                char leftChar = s[left];

                // Update minimum window tracking
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Remove character at left pointer
                windowCount[leftChar]--;
                if (targetCount[leftChar] > 0 && windowCount[leftChar] < targetCount[leftChar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};