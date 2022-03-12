class Solution {
public:
    int maxSubArray(vector<int>& nums, int left, int right) {
        auto range = to_string(left) + '-' + to_string(right);
        if (left > right)
            return INT_MIN;
        if (dp.find(range) != dp.end())
            return dp[range];
        int sum = 0;
        for (int i = left; i <= right; ++i)
            sum += nums[i];
        int resultLeft = maxSubArray(nums, left + 1, right);
        int resultRight = maxSubArray(nums, left, right - 1);
        int result = max(resultLeft, resultRight);
        int output = max(sum, result);
        dp[range] = output;
        return output;
    }
    
    int maxSubArray(vector<int>& nums) {
        dp.clear();
        
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
    
private:
    unordered_map<string, int> dp;
    
};