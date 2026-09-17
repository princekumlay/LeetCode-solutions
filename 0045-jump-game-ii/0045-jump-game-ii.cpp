class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int max_jump = 0;
        int jump = 0;
        int current_end = 0;

        for(int i = 0; i < n - 1; i++){
            max_jump = max(max_jump, i + nums[i]);

            if(i == current_end){
                jump++;
                current_end = max_jump;
            }
        }

        return jump;
    }
};