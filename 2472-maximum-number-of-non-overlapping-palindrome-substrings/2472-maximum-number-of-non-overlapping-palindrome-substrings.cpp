class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1;

        for (int i = 0; i < n; ++i) {
            // Expand for both odd and even length centers
            for (int len : {k, k + 1}) {
                int left = i - len / 2;
                int right = i + (len - 1) / 2;

                // Ensure boundaries and non-overlapping constraint
                if (left > last_end && right < n && isPalindrome(s, left, right)) {
                    count++;
                    last_end = right;
                    break; // Move greedily to the next valid segment
                }
            }
        }
        return count;
    }

private:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};