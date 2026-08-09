#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        std::vector<int> suffixSum(n);
        
        // Compute suffix sums: suffixSum[i] = sum(piles[i...n-1])
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // dp[i][M] stores the max stones a player can get starting at pile i with parameter M
        std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int M = 1; M <= n; ++M) {
                // If current player can take all remaining piles
                if (i + 2 * M >= n) {
                    dp[i][M] = suffixSum[i];
                } else {
                    int maxStones = 0;
                    for (int X = 1; X <= 2 * M; ++X) {
                        int nextM = std::max(M, X);
                        int opponentStones = dp[i + X][nextM];
                        maxStones = std::max(maxStones, suffixSum[i] - opponentStones);
                    }
                    dp[i][M] = maxStones;
                }
            }
        }

        return dp[0][1];
    }
};