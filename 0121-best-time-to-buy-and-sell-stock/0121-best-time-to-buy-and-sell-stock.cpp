class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int maxProfit = 0;

        for(int p : prices){
            buy = min(buy, p);
            maxProfit = max(maxProfit, p - buy);
        }

        return maxProfit;
    }
};