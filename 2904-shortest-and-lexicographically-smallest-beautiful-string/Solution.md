# Shortest and Lexicographically Smallest Beautiful String | Sliding Window | Beats 100%

# Intuition
The problem asks for the shortest substring containing exactly `k` ones. If there are multiple substrings of the same minimal length, we need to choose the lexicographically smallest one. Since the string length $N \le 100$, a sliding window combined with direct string comparisons provides an efficient solution.

# Approach
1. **Sliding Window Expansion:** Use a right pointer `right` to expand the window and count the number of `'1'`s.
2. **Window Shrinking:** When the count of `'1'`s reaches `k`, shrink the left pointer `left` to discard any leading `'0'`s. This guarantees that candidate substrings start with `'1'`, minimizing their length for the current `right` endpoint.
3. **Compare Candidates:** Compare the valid substring `s[left...right]` against the best candidate (`ans`):
   - Update `ans` if the current substring is strictly shorter.
   - Update `ans` if the length is equal but the substring is lexicographically smaller (`current < ans`).
4. **Advance Window:** Move `left` past the leading `'1'`, decrement the `'1'` count, and continue scanning.

# Complexity
- **Time complexity:** $\mathcal{O}(N^2)$ — Visiting each element via sliding window takes $\mathcal{O}(N)$, while extracting and comparing candidate substrings takes up to $\mathcal{O}(N)$ per valid window.
- **Space complexity:** $\mathcal{O}(1)$ — Only a few pointer variables are maintained (excluding the auxiliary space for the output string).

# Code

```cpp []
#include <string>

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int ones = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') {
                ones++;
            }

            while (ones == k) {
                while (s[left] == '0') {
                    left++;
                }

                string current = s.substr(left, right - left + 1);

                if (ans.empty() || current.length() < ans.length() || 
                   (current.length() == ans.length() && current < ans)) {
                    ans = current;
                }

                left++;
                ones--;
            }
        }

        return ans;
    }
};
```
```javascript []
var shortestBeautifulSubstring = function(s, k) {
    const n = s.length;
    let ans = "";
    let ones = 0;
    let left = 0;

    for (let right = 0; right < n; right++) {
        if (s[right] === '1') {
            ones++;
        }

        while (ones === k) {
            while (s[left] === '0') {
                left++;
            }

            const current = s.substring(left, right + 1);

            if (ans === "" || current.length < ans.length || 
               (current.length === ans.length && current < ans)) {
                ans = current;
            }

            left++;
            ones--;
        }
    }

    return ans;
};
```
```python []
class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        n = len(s)
        ans = ""
        ones = 0
        left = 0

        for right in range(n):
            if s[right] == '1':
                ones += 1

            while ones == k:
                # Shrink leading zeros to ensure the substring starts with '1'
                while s[left] == '0':
                    left += 1

                current = s[left:right + 1]

                # Update answer if current is shorter or lexicographically smaller
                if not ans or len(current) < len(ans) or (len(current) == len(ans) and current < ans):
                    ans = current

                # Move past the first '1' to look for the next valid window
                left += 1
                ones -= 1

        return ans
```
```java []
class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int n = s.length();
        String ans = "";
        int ones = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (s.charAt(right) == '1') {
                ones++;
            }

            while (ones == k) {
                while (s.charAt(left) == '0') {
                    left++;
                }

                String current = s.substring(left, right + 1);

                if (ans.isEmpty() || current.length() < ans.length() || 
                   (current.length() == ans.length() && current.compareTo(ans) < 0)) {
                    ans = current;
                }

                left++;
                ones--;
            }
        }

        return ans;
    }
}
```