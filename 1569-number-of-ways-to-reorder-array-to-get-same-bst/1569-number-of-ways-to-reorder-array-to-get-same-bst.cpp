class Solution {
    long long mod = 1e9 + 7;
    vector<vector<long long>> table;

    long long comb(int n, int k) {
        if (k == 0 || k == n) return 1;
        if (table[n][k] != -1) return table[n][k];
        return table[n][k] = (comb(n - 1, k - 1) + comb(n - 1, k)) % mod;
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long left_ways = solve(left) % mod;
        long long right_ways = solve(right) % mod;

        long long res = comb(n - 1, left.size());
        res = (res * left_ways) % mod;
        res = (res * right_ways) % mod;

        return res;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1, vector<long long>(n + 1, -1));
        // Subtract 1 because the root doesn't count towards reordering ways of subtrees directly
        return (solve(nums) - 1 + mod) % mod; 
    }
};