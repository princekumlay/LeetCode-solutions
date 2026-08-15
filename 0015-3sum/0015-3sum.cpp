class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //given that i!=j, i!=k and j!=k
        vector<vector<int>> result;
        int n = nums.size();
        //we will use two pointer approach to solve this problem but first we have to sort the array
        sort(nums.begin(), nums.end());
        //for case 1st [-4, -1, -1, 0, 1, 2]

        int left, right;

        // int i = 0;
        for(int i = 0; i < n - 2; i++){

            //skip duplicate
            if(i > 0 && nums[i] == nums[i - 1]){
            continue;
            }
            left = i + 1;
            right = n - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});

                    //if duplicate
                    while(left < right && nums[left] == nums[left + 1])
                    left++;
                    while(left < right && nums[right] == nums[right - 1])
                    right--;

                    left++;
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }

        return result;
    }
};