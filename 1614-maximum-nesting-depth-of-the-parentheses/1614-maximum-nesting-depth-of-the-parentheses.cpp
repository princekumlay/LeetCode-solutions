class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int maxDepth = 0;

        int open = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                open++;
                maxDepth = max(maxDepth, open);
            }
            else if(s[i] == ')'){
                open--;
            }
        }

        return maxDepth;
    }
};