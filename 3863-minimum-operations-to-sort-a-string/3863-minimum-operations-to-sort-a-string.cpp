class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // 1. Already sorted
        if (is_sorted(s.begin(), s.end())) return 0;
        
        // 2. Length 2 cannot be sorted if not already sorted
        if (n == 2) return -1;
        
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        
        // 3. Check for 1 operation
        // If min is at the start (proper prefix) or max is at the end (proper suffix)
        bool mn_at_start = (s[0] == mn);
        bool mx_at_end = (s[n - 1] == mx);
        
        if (mn_at_start || mx_at_end) return 1;
        
        // 4. Check if it's impossible (-1) or requires 3 operations
        // If the minimum never appears in any proper prefix or max never in proper suffix
        bool has_mn_in_prefix = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) has_mn_in_prefix = true;
        }
        
        bool has_mx_in_suffix = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) has_mx_in_suffix = true;
        }
        
        if (!has_mn_in_prefix && !has_mx_in_suffix) {
            return 3;
        }
        
        // Fallback to 2 operations
        return 2;
    }
};