class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            swap(s[left++], s[right--]);
        }

        //alternative
        // reverse(s.begin(), s.end());
    }
};