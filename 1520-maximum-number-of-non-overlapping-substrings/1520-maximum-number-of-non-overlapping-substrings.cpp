class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }

        vector<pair<int, int>> intervals; // {right, left}

        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int left = first[i];
            int right = last[i];
            bool valid = true;

            for (int j = left; j <= right; ++j) {
                int ch = s[j] - 'a';
                if (first[ch] < left) {
                    valid = false; // Pulled a character whose start is outside left
                    break;
                }
                right = max(right, last[ch]);
            }

            if (valid) {
                intervals.push_back({right, left});
            }
        }

        // Sort by ending position (right index)
        sort(intervals.begin(), intervals.end());

        vector<string> result;
        int prev_end = -1;

        for (const auto& [right, left] : intervals) {
            if (left > prev_end) {
                result.push_back(s.substr(left, right - left + 1));
                prev_end = right;
            }
        }

        return result;
    }
};