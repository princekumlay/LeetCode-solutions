class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        //put all zeros in place
        int placeZero = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                swap(nums[placeZero], nums[i]);
                placeZero++;
            }
        }

        //places 1's and 2's in place
        int back = n - 1, i = placeZero;
        while(i <= back){
            if(nums[i] == 2){
                swap(nums[back], nums[i]);
                back--;
            }
            else{
                i++;
            }
        }
    }
};