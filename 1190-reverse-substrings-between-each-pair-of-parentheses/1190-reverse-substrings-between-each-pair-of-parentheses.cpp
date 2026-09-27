
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n, 0);
        stack<int> st;

        // 1. Build pair mapping for parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int open_idx = st.top();
                st.pop();
                pair[open_idx] = i;
                pair[i] = open_idx;
            }
        }

        // 2. Traverse and build the resulting string
        string result = "";
        int step = 1; // 1 for left-to-right, -1 for right-to-left
        for (int i = 0; i < n; i += step) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];    // Teleport to matching bracket
                step = -step;   // Flip direction
            } else {
                result += s[i];
            }
        }

        return result;
    }
};