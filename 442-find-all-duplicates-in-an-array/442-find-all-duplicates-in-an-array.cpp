class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> output;
        int ptr = nums[0] - 1;
        for (int i = 0; i < nums.size(); ++i) {
            int ptr = abs(nums[i]) - 1;
            if (nums[ptr] < 0)
                output.push_back(abs(nums[i]));
            else
                nums[ptr] *= -1;
        }
        return output;
    }
};