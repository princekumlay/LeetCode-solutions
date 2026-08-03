class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber > 0){
            columnNumber--;
            char c = 'A' + (columnNumber % 26);
            ans += c;
            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};