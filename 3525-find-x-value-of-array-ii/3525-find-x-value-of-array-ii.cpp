class Solution {
    struct Node {
        int prod;
        array<int, 5> cnt; // cnt[r]: frequency of prefix products % k == r
        Node() {
            prod = 1;
            cnt.fill(0);
        }
    };

    int K;
    vector<Node> tree;

    // Merge left child and right child nodes
    Node mergeNodes(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % K;

        // Copy prefix counts from left child
        for (int r = 0; r < K; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Combine left product with prefixes in the right child
        for (int r = 0; r < K; r++) {
            if (right.cnt[r] > 0) {
                int new_rem = (left.prod * r) % K;
                res.cnt[new_rem] += right.cnt[r];
            }
        }

        return res;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int rem = nums[start] % K;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node].cnt.fill(0);
            int rem = val % K;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = mergeNodes(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }
        Node leftRes = query(2 * node, start, mid, l, r);
        Node rightRes = query(2 * node + 1, mid + 1, end, l, r);
        return mergeNodes(leftRes, rightRes);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        K = k;
        tree.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());

        for (const auto& q : queries) {
            int ind = q[0];
            int val = q[1];
            int start = q[2];
            int xVal = q[3];

            // 1. Update nums[ind] = val
            update(1, 0, n - 1, ind, val);

            // 2. Query range [start, n - 1] to get counts
            Node resNode = query(1, 0, n - 1, start, n - 1);
            result.push_back(resNode.cnt[xVal]);
        }

        return result;
    }
};