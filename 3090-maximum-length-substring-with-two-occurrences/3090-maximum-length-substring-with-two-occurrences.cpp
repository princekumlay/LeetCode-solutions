class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);
        int maxlength = 0;
        int left = 0;

        for(int right = 0; right < s.length(); ++right){
            count[s[right] - 'a']++;

            //shrink window if character occurence exceeds 2
            while(count[s[right] - 'a'] > 2){
                count[s[left] - 'a']--;
                left++;
            }

            maxlength = max(maxlength, right - left + 1);
        }

        return maxlength;
    }
};