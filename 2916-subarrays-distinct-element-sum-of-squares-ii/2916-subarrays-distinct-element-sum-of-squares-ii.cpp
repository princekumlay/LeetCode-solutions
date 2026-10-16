class Solution {
    long long mod = 1e9 + 7;
    vector<long long> tree_sum2; // Sum of squares: sum(c_i^2)
    vector<long long> tree_sum1; // Sum of elements: sum(c_i)
    vector<long long> lazy;      // Lazy propagation values

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void apply(int node, int l, int r, long long val) {
        long long len = (r - l + 1);
        // Updating sum of squares: sum((c_i + val)^2) = sum(c_i^2) + 2*val*sum(c_i) + val^2 * len
        tree_sum2[node] = (tree_sum2[node] + 2 * val * tree_sum1[node] % mod + val * val % mod * len) % mod;
        // Updating sum of elements: sum(c_i + val) = sum(c_i) + val * len
        tree_sum1[node] = (tree_sum1[node] + val * len) % mod;
        lazy[node] = (lazy[node] + val) % mod;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree_sum1[node] = (tree_sum1[2 * node] + tree_sum1[2 * node + 1]) % mod;
        tree_sum2[node] = (tree_sum2[2 * node] + tree_sum2[2 * node + 1]) % mod;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) {
            return tree_sum2[node];
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr)) % mod;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum2.assign(4 * n, 0);
        tree_sum1.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        long long total_sum = 0;
        unordered_map<int, int> last_seen;

        for (int j = 0; j < n; ++j) {
            int L = last_seen.count(nums[j]) ? last_seen[nums[j]] + 1 : 0;
            last_seen[nums[j]] = j;

            // Range update: add 1 to counts in range [L, j]
            update(1, 0, n - 1, L, j, 1);

            // Query total sum of squares of distinct counts for all subarrays ending at index j
            long long current_subarrays_sum2 = query(1, 0, n - 1, 0, j);
            total_sum = (total_sum + current_subarrays_sum2) % mod;
        }

        return total_sum;
    }
};