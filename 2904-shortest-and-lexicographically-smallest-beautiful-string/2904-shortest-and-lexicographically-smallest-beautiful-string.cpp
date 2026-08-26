#include <string>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        int n = s.length();
        string ans = "";
        int ones = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') {
                ones++;
            }

            while (ones == k) {
                // Shrink leading zeros to ensure the substring starts with '1'
                while (s[left] == '0') {
                    left++;
                }

                string current = s.substr(left, right - left + 1);

                // Update best answer if current is shorter or lexicographically smaller
                if (ans.empty() || current.length() < ans.length() || 
                   (current.length() == ans.length() && current < ans)) {
                    ans = current;
                }

                // Move past the first '1' to look for the next valid window
                left++;
                ones--;
            }
        }

        return ans;
    }
};