#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        // 1. Calculate sum of the longest sequential prefix starting at index 0
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break; // Sequential prefix ends
            }
        }
        
        // 2. Put all numbers into a hash set for O(1) lookups
        std::unordered_set<int> seen(nums.begin(), nums.end());
        
        // 3. Increment sum until we find an integer missing from nums
        while (seen.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};