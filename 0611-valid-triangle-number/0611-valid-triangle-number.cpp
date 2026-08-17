class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int count = 0;
        sort(nums.begin(), nums.end());

        //O(n^3) brute force approach
        // for(int i = 0; i < nums.size() - 2; i++){
        //     for(int j = i + 1; j < nums.size() - 1; j++){
        //         for(int k = j + 1; k < nums.size(); k++){
        //             if(nums[i] + nums[j] > nums[k]) count++;
        //         }
        //     }
        // }

        //optimized O(n^2) fixed K + two pointer approach
        for(int k = nums.size() - 1; k > 1; k--){
            int left = 0, right = k - 1;
            while(left < right){
                if(nums[left] + nums[right] > nums[k]){
                    count += right - left;
                    right--;
                }
                else{
                    left++;
                }
            }
        }
 
        return count;
    }
};