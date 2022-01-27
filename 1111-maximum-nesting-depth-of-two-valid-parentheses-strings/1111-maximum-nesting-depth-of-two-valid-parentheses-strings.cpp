class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int i, n = seq.size();
        vector<int> ans(n, 0);
        for(i = 1; i < n; i++)
        {
            if( seq[i] == seq[i - 1])
                ans[i] = 1 - ans[i - 1];
            else
                ans[i] = ans[i - 1];
        }
        return ans;
    }
};