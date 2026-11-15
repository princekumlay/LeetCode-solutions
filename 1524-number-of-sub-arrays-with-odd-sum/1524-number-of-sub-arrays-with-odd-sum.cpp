class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int oddCount = 0;
        int evenCount = 1; // Empty prefix sum (0) is even
        int parity = 0;    // 0 = even, 1 = odd

        for (int x : arr) {
            parity ^= (x & 1);
            if (parity == 1) {
                ans = (ans + evenCount) % MOD;
                oddCount++;
            } else {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
        }

        return ans;
    }
};