
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        // go[i][j][0] -> landing cell if we try to move RIGHT from (i, j)
        // go[i][j][1] -> landing cell if we try to move DOWN from (i, j)
        // Stored as a pair: {nx, ny}, or {-1, -1} if out of bounds.
        vector<vector<vector<pair<int, int>>>> go(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1})));

        // Helper lambda to simulate the recursive reflection chain
        auto simulate = [&](int start_r, int start_c, int dir) -> pair<int, int> {
            int r = start_r;
            int c = start_c;
            int d = dir; // 0: Right, 1: Down

            while (true) {
                int nr = r + (d == 1 ? 1 : 0);
                int nc = c + (d == 0 ? 1 : 0);

                // Check out of bounds
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    return {-1, -1};
                }

                // If it hits a mirror, reflect immediately
                if (grid[nr][nc] == 1) {
                    if (d == 0) {
                        // Moving right into a mirror -> turns down to cell directly below the mirror
                        r = nr;
                        c = nc;
                        d = 1; // Now moving down
                    } else {
                        // Moving down into a mirror -> turns right to cell directly right of the mirror
                        r = nr;
                        c = nc;
                        d = 0; // Now moving right
                    }
                } else {
                    // Lands on an empty cell
                    return {nr, nc};
                }
            }
        };

        // 1. Precompute the jump targets for every cell and both directions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the starting cell itself is a mirror (though (0,0) and (m-1,n-1) are guaranteed 0)
                if (grid[i][j] == 1) continue;

                // Try moving Right (dir = 0)
                if (j + 1 < n) {
                    if (grid[i][j + 1] == 1) {
                        go[i][j][0] = simulate(i, j, 0);
                    } else {
                        go[i][j][0] = {i, j + 1};
                    }
                }

                // Try moving Down (dir = 1)
                if (i + 1 < m) {
                    if (grid[i + 1][j] == 1) {
                        go[i][j][1] = simulate(i, j, 1);
                    } else {
                        go[i][j][1] = {i + 1, j};
                    }
                }
            }
        }

        // 2. DP Table in row-major order
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                // Propagate to Right move landing spot
                auto [rx, ry] = go[i][j][0];
                if (rx != -1 && ry != -1) {
                    dp[rx][ry] = (dp[rx][ry] + dp[i][j]) % MOD;
                }

                // Propagate to Down move landing spot
                auto [dx, dy] = go[i][j][1];
                if (dx != -1 && dy != -1) {
                    dp[dx][dy] = (dp[dx][dy] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};