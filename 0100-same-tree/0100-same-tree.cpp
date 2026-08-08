/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both nodes are null
        if (p == nullptr && q == nullptr) return true;
        
        // Base case 2: One is null, or values don't match
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        
        // Recursive step: Both left and right subtrees must be identical
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};