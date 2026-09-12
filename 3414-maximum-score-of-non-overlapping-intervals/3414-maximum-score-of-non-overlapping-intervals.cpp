class Solution {
    struct Interval {
        int l, r, weight, id;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals by end time
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });

        // Precompute predecessor indices using binary search
        vector<int> prev(n, -1);
        for (int i = 0; i < n; ++i) {
            int low = 0, high = i - 1, ans = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].r < arr[i].l) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            prev[i] = ans;
        }

        // DP State: dp[i][k] = max weight using a subset of first i intervals picking at most k
        // To handle lexicographical requirement cleanly, we store {max_weight, vector<int> indices}
        // or backtrack. Given K <= 4, storing vector<int> of size <= 4 directly in DP is fast enough.
        
        using State = pair<long long, vector<int>>;
        vector<vector<State>> dp(n + 1, vector<State>(5, {0LL, {}}));

        auto isBetter = [](const State& a, const State& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second; // Compare index arrays lexicographically
        };

        for (int i = 0; i < n; ++i) {
            for (int k = 1; k <= 4; ++k) {
                // Option 1: Don't pick interval i
                State best = dp[i][k];

                // Option 2: Pick interval i
                int p = prev[i];
                State prev_state = (p != -1) ? dp[p + 1][k - 1] : State{0LL, {}};
                
                long long new_weight = prev_state.first + arr[i].weight;
                vector<int> new_indices = prev_state.second;
                new_indices.push_back(arr[i].id);
                sort(new_indices.begin(), new_indices.end());

                State pick_state = {new_weight, new_indices};

                if (isBetter(pick_state, best)) {
                    best = pick_state;
                }

                dp[i + 1][k] = best;
            }
        }

        // Find the absolute best among choices of up to 4 intervals
        State result = {0LL, {}};
        for (int k = 1; k <= 4; ++k) {
            if (isBetter(dp[n][k], result)) {
                result = dp[n][k];
            }
        }

        return result.second;
    }
};