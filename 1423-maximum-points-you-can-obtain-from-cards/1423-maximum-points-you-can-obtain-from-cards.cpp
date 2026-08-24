class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int current_sum = 0;

        //take all k cards from the left
        for(int i = 0; i < k; i++){
            current_sum += cardPoints[i];
        }

        int max_score = current_sum;
        //swap cards from the left with the cards from right one by one
        for(int i = 0; i < k; i++){
            current_sum -= cardPoints[k - 1 - i];//remove card form the left
            current_sum += cardPoints[n - 1 - i];//adds card from the right
            max_score = max(max_score, current_sum);
        }
        return max_score;
    }
};