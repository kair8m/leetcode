class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> output;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int val1 = pow(nums[left], 2);
            int val2 = pow(nums[right], 2);
            if (val1 > val2) {
                output.push_back(val1);
                left++;
            } else {
                output.push_back(val2);
                right--;
            }
        }
        reverse(output.begin(), output.end());
        return output;
    }
};