class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        // dp[r] stores the number of valid subarrays ending at the previous index with remainder r
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int current_rem = num % k;

            // 1. Single element subarray starting at current position
            next_dp[current_rem] += 1;

            // 2. Extend subarrays ending at the previous position
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * current_rem) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // 3. Add current ending counts to the global results
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            // Move to next step
            dp = move(next_dp);
        }

        return result;
    }
};