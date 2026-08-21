class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // brute force approach
        //     int sum = 0;
        //     vector<int> v;
        //     for(int i = 0; i < nums.size(); i ++)
        //     {
        //       sum = sum + nums[i];
        //       for(int j = i + 1; j < nums.size(); j ++)
        //       {
        //         sum = sum + nums[j];
        //         if(sum == target)
        //         {
        //            v.push_back(i);
        //            v.push_back(j);
        //            break;
        //         }
        //         else
        //         {
        //            sum = sum - nums[j];
        //         }
        //       }
        //       sum = 0;
        //     }
        //  return v;

        // optimized approach using hash map
        unordered_map<int, int> seen = {};
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (seen.find(need) != seen.end()) {
                return {seen[need], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};