class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = nums[nums[i]];
        }
        return ans;

        /*another approach In-Place Modification in O(1) space
          int n = nums.size();
          //encoding old and new values
          for(int i = 0; i < n; i++){
            nums[i] = nums[i] + n * (nums[nums[i]] % n);
          }

          //extracting new values
          for(int i = 0; i < n; i++){
            nums[i] /= n;
          }

          return nums;
        */

    }
};