class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){

            int n = nums[i];
            int digit_sum = 0;

            while(n > 0){
                digit_sum += n % 10;
                n /= 10;
            }

            if(digit_sum == i) return i;
        }

        return -1;
    }
};