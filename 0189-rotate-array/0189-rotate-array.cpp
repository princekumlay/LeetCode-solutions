class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; //to get its correct val if k == n or k > n

        //reverse entire array elements
        int left = 0, right = n - 1;
        while(left < right){
            swap(nums[left++], nums[right--]);
        }

        //reverse first k - 1 elements
        left = 0, right = k - 1;
        while(left < right){
            swap(nums[left++], nums[right--]);
        }

        //reverse n - k elements
        left = k, right = n - 1;
        while(left < right){
            swap(nums[left++], nums[right--]);
        }

        
    }
};

