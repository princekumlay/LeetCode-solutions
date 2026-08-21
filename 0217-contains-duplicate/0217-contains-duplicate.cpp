class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        //brute force approach
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(nums[i] == nums[j]) return true;
        //     }
        // }

        //optimized approach using hash table
        unordered_set<int> seen;
        for(int num: nums){
            if(seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }
        return false;
    }
};