class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Step 1: Sort arr2 to enable binary search
        sort(arr2.begin(), arr2.end());
        int distanceValue = 0;
        
        // Step 2: Iterate through each element in arr1
        for (int x : arr1) {
            // Find the first element in arr2 that is >= x - d
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // Check if this element is also <= x + d
            // If it is, then |x - arr2[j]| <= d, so it violates the condition.
            if (it == arr2.end() || *it > x + d) {
                distanceValue++; // No conflicting element found in the range [x - d, x + d]
            }
        }
        
        return distanceValue;
    }
};