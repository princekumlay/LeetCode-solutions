class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        //take absolute values of nums and sort
        vector<long long> arr(n);
        int j = 0;
        for(int num: nums){
            arr[j++] = abs((long long)num);
        }
        sort(arr.begin(), arr.end());

        long long score = 0; 
        int mid = n / 2;

        //subtract first half
        for(int i = 0; i < mid; i++){
            score -= arr[i] * arr[i];
        }

        //add second half
        for(int i = mid; i < n; i++){
            score += arr[i] * arr[i];
        }

        return score;
    }
};