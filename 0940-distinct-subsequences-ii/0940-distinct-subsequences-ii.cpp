class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<long> last(26, 0);
        long total = 0;

        for (char ch : s) {
            int idx = ch - 'a';
            // Count of new distinct subsequences ending in `ch`
            long new_count = (total + 1) % MOD;
            
            // Update total: add new ones, subtract duplicates previously ended in `ch`
            total = (total + new_count - last[idx] + MOD) % MOD;
            
            // Update the last recorded count ending in `ch`
            last[idx] = new_count;
        }

        return total;
    }
};