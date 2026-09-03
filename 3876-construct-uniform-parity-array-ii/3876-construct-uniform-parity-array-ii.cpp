class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;

        //min odd num
        for(int n: nums1){
            if(n % 2 != 0){
                min_odd = min(min_odd, n);
            }
        }

        //no odd num exist
        if(min_odd == INT_MAX) return true;

        //check for even_num < min_odd
        for(int n: nums1){
            if(n % 2 == 0 && n < min_odd){
                return false;
            }
        }

        return true;
    }
};