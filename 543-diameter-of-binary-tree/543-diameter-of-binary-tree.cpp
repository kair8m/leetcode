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
    int diameterOfBinaryTree(TreeNode* node) {
        if (!node)
            return 0;
        int height = 0;
        int maxDiam = 0;
        diameterOfBinaryTree(node, height, maxDiam);
        return maxDiam;
    }
    
    void diameterOfBinaryTree(TreeNode* node, int& height, int &maxDiam) {
        if (!node)
        {
            height = -1;
            return;
        }
        int leftHeight = 0;
        int rightHeight = 0;
        diameterOfBinaryTree(node->left, leftHeight, maxDiam);
        diameterOfBinaryTree(node->right, rightHeight, maxDiam);
        height = 1 + max(leftHeight, rightHeight);
        int diam = leftHeight + rightHeight + 2;
        maxDiam = max(diam, maxDiam);
    }
};