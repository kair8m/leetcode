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
        unordered_map<int, int64_t> counts, sums;
        dfs(root, 0, counts, sums);
        vector<double> output(counts.size(), 0.0);
        for (const auto& entry : counts) {
            int level = entry.first;
            int count = entry.second;
            double result = double(sums[level]) / double(count);
            output[level] = result;
        }
        return output;
    }
    
    void dfs(TreeNode* node, int level, unordered_map<int, int64_t>& counts, unordered_map<int, int64_t>& sums) {
        if (!node)
            return;
        counts[level]++;
        sums[level] += node->val;
        dfs(node->left, level + 1, counts, sums);
        dfs(node->right, level + 1, counts, sums);
    }
};