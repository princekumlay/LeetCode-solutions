class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        //------------------------------------------------------------------------------------
        // double max_sum = INT_MIN;
        // // int max_sum = numeric_limits<int>::min();
        // for(int i = 0; i <= n - k; i++){
        //     double sum = 0;
        //     for(int j = i; j < i + k; j++){
        //         sum += nums[j];
        //     }
        //     max_sum = max(max_sum, sum);
        // }
        // return max_sum / k;
        //------------------------------------------------------------------------------------
        
        //optimized approach
        //calculate the first window sum
        double current_sum = 0;
        for(int i = 0; i < k; i++){
            current_sum += nums[i];
        }
        //slide window for max sum
        double max_sum = current_sum;
        for(int i = k ; i < n; i++){
            current_sum += nums[i] - nums[i - k]; //adds the right element and removes the left element
            max_sum = max(current_sum, max_sum);
        }

        return max_sum / k;
    }
};