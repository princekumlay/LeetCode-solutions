class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int length = 0;
        int left = 0;

        //better with unordered set
        // unordered_set<char> st;
        // for(int right = 0; right < n; right++){

        //     //shrink window until the duplicate is removed
        //     while(st.count(s[right])){
        //         st.erase(s[left]);
        //         left++;
        //     }

        //     //insert current character and update length
        //     st.insert(s[right]);
        //     length = max(length, right - left + 1);
        // }

        //optimized with last_seen map
        unordered_map<char, int> last_seen;
        for(int right = 0; right < n; right++){
            if(last_seen.count(s[right]) && last_seen[s[right]] >= left){
                left = last_seen[s[right]] + 1;
            }

            last_seen[s[right]] = right;
            length = max(length, right - left + 1);
        }

        return length;
    }
};