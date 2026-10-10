class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = (long long) k1 + k2;

        int maxDiff = 0;
        //find max difference to size frequency array
        vector<long long> count(100005, 0);

        for(int i = 0; i < n; i++){
            int d = abs(nums1[i] - nums2[i]);
            count[d]++;
            maxDiff = max(maxDiff, d);
        }

        //reduce from the largest difference
        for(int d = maxDiff; d > 0; d--){
            if(count[d] == 0) continue;

            //we have to reduce these elements to d - 1
            long long opsNeeded = count[d];
            if(totalOps >= opsNeeded){
                totalOps -= opsNeeded;
                count[d] = 0;
                count[d - 1] += opsNeeded;
            }
            else{
                count[d] -= totalOps;
                count[d - 1] += totalOps;
                totalOps = 0;
                break;
            }
        }

        //calculate final sum
        long long minSumSqDiff =  0;
        for(int d = 0; d <= maxDiff; d++){
            if(count[d] > 0){
                minSumSqDiff += count[d] * (long long)d * d;
            }
        }

        return minSumSqDiff;
    }
};