class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[4] = {0, 0, 0, 0};

        for (int i = n - 1; i >= 0; --i) {
            int take = 0;
            int maxDiff = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; ++k) {
                take += stoneValue[i + k];
                maxDiff = max(maxDiff, take - dp[(i + k + 1) % 4]);
            }
            dp[i % 4] = maxDiff;
        }

        int aliceDiff = dp[0];
        if (aliceDiff > 0) return "Alice";
        if (aliceDiff < 0) return "Bob";
        return "Tie";
    }
};