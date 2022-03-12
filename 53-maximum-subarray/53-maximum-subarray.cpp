class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefix = 0;
        int result = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (prefix < 0)
                prefix = nums[i];
            else
                prefix += nums[i];
            result = max(result, prefix);
        }
        
        return result;
    }
};