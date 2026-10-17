class Solution {
public:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Store elements with their original indices and digit sums
        vector<pair<pair<int, int>, int>> arr(n); // {{digit_sum, value}, original_index}
        for (int i = 0; i < n; ++i) {
            arr[i] = {{getDigitSum(nums[i]), nums[i]}, i};
        }
        
        // Step 2: Sort based on digit sum, then value
        sort(arr.begin(), arr.end());
        
        // Step 3: Find cycles to calculate minimum swaps
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position
            if (visited[i] || arr[i].second == i) continue;
            
            // Traverse the cycle
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second;
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};