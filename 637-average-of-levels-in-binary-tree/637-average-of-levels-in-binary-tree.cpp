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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> count;
        vector<double> res;
        average(root, 0, res, count);
        for (int i = 0; i < res.size(); ++i) {
            res[i] = res[i] / double(count[i]);
        }
        return res;
    }
    
    void average(TreeNode* node, int level, vector<double>& res, vector<int>& count) {
        if (!node)
            return;
        if (level >= res.size()) {
            res.push_back(node->val);
            count.push_back(1);
        } else {
            res[level] += node->val;
            count[level]++;
        }
        average(node->left, level + 1, res, count);
        average(node->right, level + 1, res, count);
    }
};