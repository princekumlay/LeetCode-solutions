class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        unordered_set<int> present(nums.begin(), nums.end());
        vector<int> missing;
        
        for (int i = minVal; i <= maxVal; ++i) {
            if (present.find(i) == present.end()) {
                missing.push_back(i);
            }
        }
        
        return missing;
    }
};