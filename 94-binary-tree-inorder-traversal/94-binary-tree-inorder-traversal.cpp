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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> output;
        auto result1 = inorderTraversal(root->left);
        for (auto val : result1)
            output.push_back(val);
        output.push_back(root->val);
        auto result2 = inorderTraversal(root->right);
        for (auto val : result2)
            output.push_back(val);
        return output;
    }
};