class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int count = 0;
        for (int num : nums) {
            if (result != num) {
                if (count == 0)
                    result = num;
                else
                    count--;
            } else {
                count++;
            }
        }
        return result;
    }
};