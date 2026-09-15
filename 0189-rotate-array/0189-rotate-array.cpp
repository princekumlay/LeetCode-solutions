class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        //reverse array elements
        reverse(nums.begin(), nums.end());

        //reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        //reverse last n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};