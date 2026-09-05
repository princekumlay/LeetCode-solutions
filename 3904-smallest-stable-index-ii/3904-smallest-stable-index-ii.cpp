class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> min_val_of_index(n);

        //minimum of every index
        min_val_of_index[n - 1] = nums[n - 1];
        int min_val = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            min_val = min(min_val, nums[i]);
            min_val_of_index[i] = min_val;
        }

        //check for stability
        int max_val = nums[0];
        for(int i = 0; i < n; i++){
            max_val = max(max_val, nums[i]);
            if(max_val - min_val_of_index[i] <= k){
                return i;
            }
        }
        return -1;
    }
};