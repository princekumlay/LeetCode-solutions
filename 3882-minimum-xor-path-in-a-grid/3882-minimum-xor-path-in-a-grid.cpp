class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[j] will store a bitset of all possible XOR values at column j for the current row
        vector<bitset<1024>> dp(n);
        
        // Base case: starting cell (0, 0)
        dp[0].set(grid[0][0]);
        
        // Fill first row
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1];
            // Shift or rebuild bitset for the new XOR value with grid[0][j]
            bitset<1024> next_set;
            for (int x = 0; x < 1024; ++x) {
                if (dp[j].test(x)) {
                    next_set.set(x ^ grid[0][j]);
                }
            }
            dp[j] = next_set;
        }
        
        // Fill the rest of the grid
        for (int i = 1; i < m; ++i) {
            // Process first column of the current row (comes only from top)
            bitset<1024> next_col_0;
            for (int x = 0; x < 1024; ++x) {
                if (dp[0].test(x)) {
                    next_col_0.set(x ^ grid[i][0]);
                }
            }
            dp[0] = next_col_0;
            
            // Process remaining columns (comes from top or left)
            for (int j = 1; j < n; ++j) {
                bitset<1024> combined = dp[j] | dp[j - 1];
                bitset<1024> next_set;
                for (int x = 0; x < 1024; ++x) {
                    if (combined.test(x)) {
                        next_set.set(x ^ grid[i][j]);
                    }
                }
                dp[j] = next_set;
            }
        }
        
        // Find the smallest x that is possible at the bottom-right cell (m-1, n-1)
        for (int x = 0; x < 1024; ++x) {
            if (dp[n - 1].test(x)) {
                return x;
            }
        }
        
        return 0;
    }
};