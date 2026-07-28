#include <string>
#include <algorithm>

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int half_len = n / 2;

        // Take the first half of the string and sort it
        string half = s.substr(0, half_len);
        sort(half.begin(), half.end());

        // Reconstruct the full palindrome
        string result = half;
        if (n % 2 != 0) {
            result += s[half_len]; // Add middle character for odd lengths
        }
        string right_half = half;
        reverse(right_half.begin(), right_half.end());
        result += right_half;

        return result;
    }
};