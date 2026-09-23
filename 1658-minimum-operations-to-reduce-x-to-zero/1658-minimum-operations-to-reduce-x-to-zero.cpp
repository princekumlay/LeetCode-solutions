
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;

        // If target is negative, x is greater than total sum
        if (target < 0) return -1;
        // If target is 0, we need to take all elements
        if (target == 0) return nums.size();

        int maxLen = -1;
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];

            // Shrink window if sum exceeds target
            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }

            // Record maximum window length when sum matches target
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : (nums.size() - maxLen);
    }
};