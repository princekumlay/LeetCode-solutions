class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int k = 2; // Start inserting from index 2
        for (int i = 2; i < nums.size(); i++) {
            // Compare current element with the element two steps back in the result
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};