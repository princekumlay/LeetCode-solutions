class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        int open = 0, close = 0;

        for(char c : s){
            if(c == '('){
                open++;
            }
            else{
                if(open > 0) open--;
                else close++;
            }
        }

        return open + close;
    }
};