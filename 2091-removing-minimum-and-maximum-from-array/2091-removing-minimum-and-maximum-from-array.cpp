class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0, max_idx = 0;

        for (int k = 0; k < n; ++k) {
            if (nums[k] < nums[min_idx]) min_idx = k;
            if (nums[k] > nums[max_idx]) max_idx = k;
        }

        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        int remove_both_front = j + 1;
        int remove_both_back = n - i;
        int remove_both_sides = (i + 1) + (n - j);

        return min({remove_both_front, remove_both_back, remove_both_sides});
    }
};