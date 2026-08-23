
class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int sumDiff = 0;
        int qDiff = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') qDiff++;
            else sumDiff += (num[i] - '0');
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') qDiff--;
            else sumDiff -= (num[i] - '0');
        }

        // If total '?' count is odd, Alice always wins
        if ((qDiff % 2 != 0 && qDiff % 2 != -2) && (qDiff & 1)) {
            return true;
        }

        // Bob wins if and only if the sum imbalance exactly cancels out 4.5 per '?'
        return (2 * sumDiff + 9 * qDiff) != 0;
    }
};