class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> output;
        for (int num : nums)
            nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0)
                continue;
            output.push_back(i + 1);
        }
        return output;
    }
};