#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp[i][j] stores relative advantage in range [i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base cases: single pile left
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // Fill table for sub-array lengths from 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i + 1][j], 
                               piles[j] - dp[i][j - 1]);
            }
        }

        // If score difference > 0, Alice wins
        return dp[0][n - 1] > 0;
    }
};