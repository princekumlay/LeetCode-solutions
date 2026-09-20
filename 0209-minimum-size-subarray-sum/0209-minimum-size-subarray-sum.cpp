class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minSize = INT_MAX;
        int left = 0, sum = 0;

        for(int right = 0; right < n; right++){
            sum += nums[right];

            while(sum >= target){
                minSize = min(minSize, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minSize == INT_MAX) ? 0 : minSize;
    }
};