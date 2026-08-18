class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        
        // int j = 0;
        // for(int i = 0; i < n; i ++){
        //     if(nums[i] != 0){
        //         swap(nums[j], nums[i]);
        //         j++;
        //     }
        // }

       // optimized approach 
        int slow = 0; 
        for(int fast = 0; fast < n; fast++){
            if(nums[fast] != 0){
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
        
    }
};