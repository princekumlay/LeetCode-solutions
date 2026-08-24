class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n || k < 0) return 0;
        
        unordered_set<int> seen;//dynamic window size
        long long max_sum = 0;
        long long current_sum = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            // If duplicate found, shrink window from left until duplicate is removed
            while(seen.count(nums[right])){
                seen.erase(nums[left]);
                current_sum -= nums[left];
                left++;
            }

            //insert the unique element to the window
            seen.insert(nums[right]);
            current_sum += nums[right];

            //when window size equals k
            if(right - left + 1 == k){
                max_sum = max(max_sum, current_sum);

                //slide window removing left most element
                seen.erase(nums[left]);
                current_sum -= nums[left];
                left++;
            }
        }
        return max_sum;
    }
};