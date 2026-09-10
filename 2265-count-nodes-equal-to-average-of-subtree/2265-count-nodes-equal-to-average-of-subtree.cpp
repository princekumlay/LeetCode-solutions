class Solution {
    int matchingNodes = 0;

    // Returns {subtree_sum, node_count}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int currentSum = node->val + leftSum + rightSum;
        int currentCount = 1 + leftCount + rightCount;

        if (node->val == currentSum / currentCount) {
            matchingNodes++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodes;
    }
};