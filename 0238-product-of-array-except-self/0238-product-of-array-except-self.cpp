class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //brute force method
        // vector<int> productArray(n, 1);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         if(j == i) continue;
        //         productArray[i] *= nums[j];
        //     }
        // }
        // return productArray;


        //optimized approach prefix and suffix
        vector<int> result(n);

        //calculate product left of i'th element
        int prefix = 1;
        for(int i = 0; i < n; i++){
            result[i] = prefix;
            prefix *= nums[i];
        }
        //calculate product right of i'th element
        int suffix = 1; 
        for(int i = n - 1; i >= 0; i--){
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};