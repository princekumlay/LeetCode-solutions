
class Solution {
private:
    void backtrack(int open, int close, int n, string& current, vector<string>& result) {
        // Base case: formed a valid combination of length 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add an opening bracket if we haven't reached 'n'
        if (open < n) {
            current.push_back('(');
            backtrack(open + 1, close, n, current, result);
            current.pop_back(); // Backtrack
        }

        // Choice 2: Add a closing bracket if it won't exceed opening brackets
        if (close < open) {
            current.push_back(')');
            backtrack(open, close + 1, n, current, result);
            current.pop_back(); // Backtrack
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        backtrack(0, 0, n, current, result);
        return result;
    }
};