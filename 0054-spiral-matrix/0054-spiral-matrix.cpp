class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        int left = 0, right = c - 1, top = 0, bottom = r - 1;
        vector<int> ans;

        while(left <= right && top <= bottom){

            //print from left to right
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //print top to bottom
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //print right to left
            if(top <= bottom && left <= right){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            //print bottom to top
            if(top <= bottom && left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};