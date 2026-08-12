class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;

            // Shrink window until the frequency of nums[right] is at most k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            // Valid window size
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};