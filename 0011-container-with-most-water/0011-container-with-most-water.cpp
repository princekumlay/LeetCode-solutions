class Solution {
public:
    int maxArea(vector<int>& height) {

        //O(n^2) approach
        int maxWater = 0;
        // for(int i = 0; i < height.size() - 1; i++){
        //     for(int j = i + 1; j < height.size(); j++){
        //         maxWater = max(maxWater, ((j - i) * min(height[i], height[j])));
        //     }
        // }

        //O(n) optimized approach
        int left = 0, right = height.size() - 1;
        while(left < right){
            maxWater = max(maxWater, ((right - left) * min(height[left], height[right])));

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxWater;
    }
};