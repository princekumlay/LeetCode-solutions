class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx = - 1;

        //find the break point
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                indx = i;
                break;
            }
        }

        //if there is no break point
        if(indx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        //if there is a break point then find the next greater num
        for(int i = n - 1; i >= indx; i--){
            if(nums[i] > nums[indx]){
                swap(nums[i], nums[indx]);
                break;
            }
        }

        //reverse the remaining elements after the break point
        reverse(nums.begin() + indx + 1, nums.end());
    }
};