class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int pushes = 0;
        
        pushes += min(n, 8) * 1;
        if (n > 8)  pushes += min(n - 8, 8) * 2;
        if (n > 16) pushes += min(n - 16, 8) * 3;
        if (n > 24) pushes += (n - 24) * 4;
        
        return pushes;

        // //approach 2
        // int ans = 0;
        // for (int i = 0; i < word.size(); i++) {
        //     ans += (i / 8) + 1;
        // }
        // return ans;
    }
};