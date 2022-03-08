/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        TreeNode* curr = root;
        while (curr) {
            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else
                return curr;
        }
        return nullptr;
    }

    void lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* lca) {
        if (!node)
            return;
        if (node->val < lca->val)
            lca = node;
        lowestCommonAncestor(node->left, p, q, lca);
        lowestCommonAncestor(node->right, p, q, lca);
    }
    
};