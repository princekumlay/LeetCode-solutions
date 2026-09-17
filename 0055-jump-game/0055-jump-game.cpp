class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        int n = nums.size();
        if(n <= 1) return true;

        for(int i = 0; i < n; i++){
            //if current index is beyond furthest reachable index
            if(i > max_jump) return false;

            //furthest reachable index from current index
            max_jump = max(max_jump, i + nums[i]);

            //if max_jump covers the last index
            if(max_jump >= n - 1) return true;
        }

        return false;
    }
};