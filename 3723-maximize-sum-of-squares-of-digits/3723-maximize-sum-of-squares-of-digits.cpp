class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Check if the sum is within the valid range
        if ((long long)num * 9 < sum || sum < 1) {
            return "";
        }
        
        string result(num, '0');
        for (int i = 0; i < num; ++i) {
            int digit = min(9, sum);
            result[i] = '0' + digit;
            sum -= digit;
        }
        
        return result;
    }
};