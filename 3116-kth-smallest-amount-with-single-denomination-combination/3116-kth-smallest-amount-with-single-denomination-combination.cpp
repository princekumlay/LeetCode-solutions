#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
    // Safe LCM helper that prevents integer overflow beyond target
    long long safeLcm(long long a, long long b, long long limit) {
        long long g = std::gcd(a, b);
        // Check if (a / g) * b will overflow or exceed limit
        if (a / g > limit / b) return limit + 1;
        return (a / g) * b;
    }

    long long countAmounts(long long target, const std::vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bit_count = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    bit_count++;
                    current_lcm = safeLcm(current_lcm, coins[i], target);
                    if (current_lcm > target) break; // Early prune
                }
            }

            if (current_lcm <= target && current_lcm > 0) {
                long long multiples = target / current_lcm;
                if (bit_count % 2 == 1) {
                    count += multiples;
                } else {
                    count -= multiples;
                }
            }
        }
        return count;
    }

public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        long long low = 1;
        long long high = (long long)(*std::min_element(coins.begin(), coins.end())) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};