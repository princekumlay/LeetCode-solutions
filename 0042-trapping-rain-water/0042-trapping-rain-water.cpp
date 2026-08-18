class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // If the array is empty, no water can be trapped.

        int left = 0, right = n - 1; // Initialize two pointers at the start and end of the array.
        int leftMax = 0, rightMax = 0; // Variables to store the maximum heights from the left and right.
        int waterTrapped = 0; // Variable to accumulate the total trapped water.

        while (left < right) { // Continue until the two pointers meet.
            if (height[left] < height[right]) { // If the height at the left pointer is less than the height at the right pointer.
                if (height[left] >= leftMax) {
                    leftMax = height[left]; // Update leftMax if the current height is greater.
                } else {
                    waterTrapped += leftMax - height[left]; // Calculate trapped water at the left pointer.
                }
                left++; // Move the left pointer to the right.
            } else { // If the height at the right pointer is less than or equal to the height at the left pointer.
                if (height[right] >= rightMax) {
                    rightMax = height[right]; // Update rightMax if the current height is greater.
                } else {
                    waterTrapped += rightMax - height[right]; // Calculate trapped water at the right pointer.
                }
                right--; // Move the right pointer to the left.
            }
        }

        return waterTrapped; // Return the total amount of trapped water.
    }
};
