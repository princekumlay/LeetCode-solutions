#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    // Computes C(n, r) capped at max_k to avoid overflow
    long long nCr(int n, int r, long long max_k) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r; // Symmetry
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > max_k) return max_k; // Cap to prevent overflow
        }
        return res;
    }

    // Computes total permutations of remaining character frequencies capped at max_k
    long long countPermutations(const vector<int>& counts, long long max_k) {
        int total = 0;
        for (int c : counts) total += c;
        
        long long ways = 1;
        int rem = total;
        for (int c : counts) {
            if (c > 0) {
                ways *= nCr(rem, c, max_k);
                if (ways >= max_k) return max_k;
                rem -= c;
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        // Find middle char for odd length
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid = 'a' + i;
            }
            freq[i] /= 2; // Keep half count
        }
        
        int half_len = n / 2;
        long long long_k = k;
        
        // Check if total combinations is less than k
        if (countPermutations(freq, long_k + 1) < long_k) {
            return "";
        }
        
        string prefix = "";
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (freq[c] == 0) continue;
                
                // Try choosing character c
                freq[c]--;
                long long combinations = countPermutations(freq, long_k + 1);
                
                if (combinations >= long_k) {
                    prefix += (char)('a' + c);
                    break; // Fix character c at position i
                } else {
                    long_k -= combinations; // Skip these permutations
                    freq[c]++; // Backtrack and try next character
                }
            }
        }
        
        // Construct final string
        string suffix = prefix;
        reverse(suffix.begin(), suffix.end());
        
        if (n % 2 != 0) {
            return prefix + mid + suffix;
        }
        return prefix + suffix;
    }
};