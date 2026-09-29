#include <vector>

using namespace std;

class Solution {
    int memo[100][100][101];

    bool dfs(int r, int c, int open, vector<vector<char>>& grid, int m, int n) {
        // Adjust current balance
        open += (grid[r][c] == '(' ? 1 : -1);

        // Prefix balance can never be negative
        if (open < 0) return false;

        // Base case: bottom-right corner
        if (r == m - 1 && c == n - 1) {
            return open == 0;
        }

        // Return cached result if visited
        if (memo[r][c][open] != -1) {
            return memo[r][c][open];
        }

        bool hasPath = false;
        // Move Down
        if (r + 1 < m) {
            hasPath = hasPath || dfs(r + 1, c, open, grid, m, n);
        }
        // Move Right
        if (!hasPath && c + 1 < n) {
            hasPath = hasPath || dfs(r, c + 1, open, grid, m, n);
        }

        return memo[r][c][open] = hasPath;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even to be valid
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        // Reset memoization table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n) / 2; ++k) {
                    memo[i][j][k] = -1;
                }
            }
        }

        return dfs(0, 0, 0, grid, m, n);
    }
};