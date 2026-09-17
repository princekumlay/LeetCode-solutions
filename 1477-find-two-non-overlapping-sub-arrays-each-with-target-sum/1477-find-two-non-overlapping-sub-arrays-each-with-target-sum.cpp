class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);
        
        int left = 0;
        int window_sum = 0;
        int min_total_len = INT_MAX;
        int min_single_len = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            window_sum += arr[right];
            
            while (window_sum > target) {
                window_sum -= arr[left];
                left++;
            }
            
            if (window_sum == target) {
                int curr_len = right - left + 1;
                
                // Check if a valid non-overlapping subarray exists to the left
                if (left > 0 && best[left - 1] != INT_MAX) {
                    min_total_len = min(min_total_len, curr_len + best[left - 1]);
                }
                
                min_single_len = min(min_single_len, curr_len);
            }
            
            best[right] = min_single_len;
        }
        
        return min_total_len == INT_MAX ? -1 : min_total_len;
    }
};