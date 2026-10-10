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
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[slow] == 0) {
                if (nums[fast] != 0) {
                    swap(nums[slow++], nums[fast]);
                }
            }
            else{
                slow++;
            }
        }
        
    }
};