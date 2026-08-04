class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> missing;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int val = nums[i] + 1; val < nums[i + 1]; ++val) {
                missing.push_back(val);
            }
        }
        
        return missing;
    }
};