class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        unordered_map<int, int> count;
        for(int d : digits) {
            count[d]++;
        }

        int valid_count = 0;

        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;       // hundreds place
            int d2 = (num / 10) % 10; // tens place
            int d3 = num % 10;

            unordered_map<int, int> freq;
            freq[d1]++;
            freq[d2]++;
            freq[d3]++;

            bool possible = true;
            for (auto& [digit, req] : freq) {
                if (count[digit] < req) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                valid_count++;
        }
        return valid_count;
    }
};