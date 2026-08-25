class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int multiple_of_k = k;
        while(seen.count(multiple_of_k)){
            multiple_of_k += k;
        }

        return multiple_of_k;
    }
};