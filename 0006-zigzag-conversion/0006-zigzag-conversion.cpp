class Solution {
public:
    string convert(string s, int numRows) {
        //base case
        if(numRows == 1 || numRows >= s.length()) return s;

        //rows = ["", "", ""]
        vector<string> rows(min(static_cast<int>(s.length()), numRows));
        int currRow = 0;
        bool goingDown = false;

        for(char c : s){
            rows[currRow] += c;

            if(currRow == 0 || currRow == numRows - 1){
                goingDown = !goingDown;
            }

            currRow += goingDown ? 1 : -1;
        }

        //combine all rows
        string result;
        for(const string& row : rows){
            result += row;
        }

        return result;
    }
};