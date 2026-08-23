class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int maxStreak = 0;

        for(int num: st){
            if(!st.count(num - 1)){
                int currentNum = num;
                int currentStreak = 1;

                while(st.count(currentNum + 1)){
                    currentNum++;
                    currentStreak++;
                }

                maxStreak = max(maxStreak, currentStreak);
            }
        }
        return maxStreak;
    }
};