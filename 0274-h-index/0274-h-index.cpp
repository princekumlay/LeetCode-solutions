class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);

        for(int c : citations){
            if(c >= n) count[n]++;
            else count[c]++;
        }

        int total_papers = 0;
        for(int i = n; i >= 0; i--){
            total_papers += count[i];
            if(total_papers >= i) return i;
        }

        return 0;
    }
};