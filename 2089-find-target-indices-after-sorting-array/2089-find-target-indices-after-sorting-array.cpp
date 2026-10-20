class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        int lessCount = 0, equalCount = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < target) lessCount++;
            else if(nums[i] == target) equalCount++;
        }

        for(int i = 0; i < equalCount; i++){
            ans.push_back(lessCount + i);
        }

        return ans;
    }
};