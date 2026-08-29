#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        
        // Sort based on values
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> result(n);
        int i = 0;
        
        while (i < n) {
            int j = i;
            // Identify connected components
            while (j + 1 < n && sorted_nums[j + 1].first - sorted_nums[j].first <= limit) {
                j++;
            }
            
            // Extract indices for the current group
            vector<int> indices;
            for (int k = i; k <= j; ++k) {
                indices.push_back(sorted_nums[k].second);
            }
            
            // Sort indices to place values from smallest index to largest
            sort(indices.begin(), indices.end());
            
            // Assign sorted values back to original sorted index positions
            for (int k = i; k <= j; ++k) {
                result[indices[k - i]] = sorted_nums[k].first;
            }
            
            i = j + 1;
        }
        
        return result;
    }
};