class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // 1. Assign two 64-bit random values per unique number for parity hashing
        mt19937_64 rng1(1337), rng2(7331);
        unordered_map<int, unsigned long long> val_hash1, val_hash2;
        for (int x : nums) {
            if (!val_hash1.count(x)) {
                val_hash1[x] = rng1();
                val_hash2[x] = rng2();
            }
        }

        // 2. Build positional XOR hashes (XOR values only on odd-to-even toggles)
        vector<unsigned long long> pref1(n + 1, 0), pref2(n + 1, 0);
        unordered_map<int, int> freq_map;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            freq_map[x]++;
            pref1[i + 1] = pref1[i];
            pref2[i + 1] = pref2[i];

            // If occurrence becomes even, XOR the value into the prefix
            if (freq_map[x] % 2 == 0) {
                pref1[i + 1] ^= val_hash1[x];
                pref2[i + 1] ^= val_hash2[x];
            }
        }

        // 3. Offline Range Distinct Count using Fenwick Tree
        unordered_map<int, int> last_pos;
        vector<int> prev_occ(n, -1);
        for (int i = 0; i < n; ++i) {
            if (last_pos.count(nums[i])) {
                prev_occ[i] = last_pos[nums[i]];
            }
            last_pos[nums[i]] = i;
        }

        vector<vector<pair<int, int>>> query_buckets(n);
        for (int i = 0; i < q; ++i) {
            query_buckets[queries[i][1]].push_back({queries[i][0], i});
        }

        vector<int> bit(n + 1, 0);
        auto update = [&](int idx, int val) {
            for (++idx; idx <= n; idx += idx & -idx) bit[idx] += val;
        };
        auto query = [&](int idx) {
            int sum = 0;
            for (++idx; idx > 0; idx -= idx & -idx) sum += bit[idx];
            return sum;
        };

        vector<int> distinct_cnt(q, 0);
        for (int r = 0; r < n; ++r) {
            if (prev_occ[r] != -1) {
                update(prev_occ[r], -1);
            }
            update(r, 1);

            for (auto& q_pair : query_buckets[r]) {
                int l = q_pair.first;
                int q_id = q_pair.second;
                distinct_cnt[q_id] = query(r) - query(l - 1);
            }
        }

        // 4. Standard Prefix XOR Parity Check
        unordered_map<int, unsigned long long> h1, h2;
        for (int x : nums) {
            if (!h1.count(x)) {
                h1[x] = val_hash1[x];
                h2[x] = val_hash2[x];
            }
        }

        vector<unsigned long long> std_pref1(n + 1, 0), std_pref2(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            std_pref1[i + 1] = std_pref1[i] ^ h1[nums[i]];
            std_pref2[i + 1] = std_pref2[i] ^ h2[nums[i]];
        }

        vector<bool> ans(q, false);
        for (int i = 0; i < q; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];

            bool even1 = ((std_pref1[r + 1] ^ std_pref1[l]) == 0);
            bool even2 = ((std_pref2[r + 1] ^ std_pref2[l]) == 0);
            bool valid_k = (distinct_cnt[i] == k);

            ans[i] = even1 && even2 && valid_k;
        }

        return ans;
    }
};