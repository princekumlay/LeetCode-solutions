class Solution {
public:
    int reverseDegree(string s) {
        long long degree = 0;
        
        for(int i = 0; i < s.length(); i++){
            int factor = ('z' - s[i] + 1) * (i + 1);
            degree += factor;
        }

        return degree;
    }
};