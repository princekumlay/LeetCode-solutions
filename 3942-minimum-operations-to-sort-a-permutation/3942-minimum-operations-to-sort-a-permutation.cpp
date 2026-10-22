class Solution {
public:
    int n;
    
    int findSteps(vector<int>& nums, bool isInc = true) {
        int s = isInc ? 1 : n - 2;
        int e = isInc ? n : -1;
        int d = (isInc << 1) - 1;
        int i, j;
        
        for (i = s; i != e; i += d) {
            if (nums[i - d] > nums[i]) break;
        }
        
        if (i == e) return 1 - isInc;
        if (nums[e - d] > nums[s - d]) return -1;
        
        for (j = i + d; j != e; j += d) {
            if (nums[j - d] > nums[j]) break;
        }
        
        if (j != e) return -1;
        
        int k = i + 1 - isInc;
        return min(k + 1 - isInc, n - k + 1 + isInc);
    }

    int minOperations(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return 0;
        
        int step = findSteps(nums, true);
        if (step != -1) return step;
        
        return findSteps(nums, false);
    }
};