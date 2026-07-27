class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry left, we can return early
            }
            digits[i] = 0; // Carry over to the next digit
        }

        // If all digits were 9 (e.g., [9, 9, 9] -> [0, 0, 0])
        digits.insert(digits.begin(), 1);
        return digits;
    }
};