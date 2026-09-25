class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> resultSet = parse(expression, i);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> parse(const string& expr, int& i) {
        set<string> res; // Stores unions (comma-separated results)
        set<string> cur = {""}; // Stores current concatenation term

        while (i < expr.length() && expr[i] != '}') {
            if (expr[i] == ',') {
                // Union current term into result and reset cur
                res.insert(cur.begin(), cur.end());
                cur = {""};
                i++;
            } else if (expr[i] == '{') {
                i++; // Skip '{'
                set<string> nextSet = parse(expr, i);
                i++; // Skip '}'
                cur = multiply(cur, nextSet);
            } else {
                // Single character letter
                string s(1, expr[i]);
                cur = multiply(cur, {s});
                i++;
            }
        }

        // Union the final remaining term
        res.insert(cur.begin(), cur.end());
        return res;
    }

    // Helper to compute Cartesian product of two sets of strings
    set<string> multiply(const set<string>& s1, const set<string>& s2) {
        set<string> res;
        for (const string& a : s1) {
            for (const string& b : s2) {
                res.insert(a + b);
            }
        }
        return res;
    }
};